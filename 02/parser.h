typedef void(*token_begin_f)();
typedef void(*token_end_f)();
typedef void(*token_word_f)(const char* token_str);
typedef void(*token_number_f)(int token_num);

void init_begin_f();
void init_end_f();
void init_word_f(const char* token_str);
void init_number_f(int token_num);

void proc(bool b_ch, bool b_num, token_word_f str_f, token_number_f num_f);
void parser(const char* text, token_word_f str_f = &init_word_f,
	    token_number_f num_f = &init_number_f,
	    token_begin_f begin = &init_begin_f,
	    token_end_f end = &init_end_f);
