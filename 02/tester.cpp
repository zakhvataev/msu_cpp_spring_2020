#include <iostream>
#include "parser.h"

void token_begin(){
	std::cout << std::endl;
	std::cout << "____Start!!!____" << std::endl;
}
void token_end(){
	std::cout << "____End!!!_______" << std::endl;
	std::cout << std::endl;
}
void token_word_1(const char* token_str){
	std::cout << "Token_str: " << token_str << ";" << std::endl;
}
void token_word_2(const char* token_str){
	std::cout << "Another output of word: {" << token_str << "}" << std::endl;
}
void token_number_1(int token_num){
	std::cout << "Token_num: " << token_num << "; token % 2 = " << token_num % 2 << std::endl;
}
void token_number_2(int token_num){
	std::cout << "Another output of number: (" << token_num << ")" << std::endl;
}

void test(){
	char text1[] = "2 mrfm u3ri2 213213 23210 dsfnl";
	char text2[] = "sf 7d77 323 jroe 92932 fefe 2939";
	
	std::cout<<"TEST1: " << text1 << std::endl;
	parser(text1, token_word_1, token_number_1, token_begin, token_end);

	std::cout<<"TEST2: " << text2 << std::endl;
	parser(text2, token_word_2, token_number_2, token_begin, token_end);
}
