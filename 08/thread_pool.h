#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <functional>
#include <vector>
#include <queue>


class ThreadPool {
    std::vector<std::thread> threads;
    std::mutex m;
    std::queue<std::function<void()> > tasks;
    size_t size;
    std::atomic<bool> f;
    std::condition_variable condition;

    void in_proc() {
        while(!f) {
            std::unique_lock<std::mutex> lock(m);
            if (tasks.empty()) {
                condition.wait(lock);
            } else {
                auto problem(std::move(tasks.front()));
                tasks.pop();
                lock.unlock();
                problem();
            }
        }
    }

public:
    explicit ThreadPool(size_t poolSize) :size(poolSize), f(false) {
        for(int i = 0; i < poolSize; ++i) {
            threads.emplace_back(std::thread([this]() {
                this->in_proc();
            }));
        }
    }
    
    ~ThreadPool() {
        f = true;
        condition.notify_all();
        for(int i = 0; i < size; i++) {
            threads[i].join();
        }
    }
    
    template <class Func, class... Args>
    auto exec(Func func, Args... args) -> std::future<decltype(func(args...))> {
        auto problem = std::make_shared<std::packaged_task<decltype(func(args...))()> >([func, args...](){
            return func(args...);
        });
        auto res = problem->get_future();
        std::unique_lock<std::mutex> lock(m);
        tasks.push([problem]() {(*problem)();});
        condition.notify_one();
        return res;
    }
};