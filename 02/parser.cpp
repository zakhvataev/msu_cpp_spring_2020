#include <iostream>
#include <string>
#include "parser.h"

void init_begin_f(){}
void init_end_f(){}
void init_word_f(const char* token_str){}
void init_number_f(int token_num){}

void proc(const char* str, int num, bool b_ch,
	  bool b_num, token_word_f str_f, 
	  token_number_f num_f){

	if(b_ch && b_num) ;
	else if(b_ch) str_f(str);
	else num_f(num);
}

void parser(const char* text, token_word_f str_f, token_number_f num_f,
	    token_begin_f begin, token_end_f end){
	begin();
	int i = 0;
	int token_num = 0;
	std::string token_str = "";
	bool b_ch = false;
	bool b_num = false;

	while(text[i]){

		if(text[i] != '\n' && text[i] != ' ' && text[i] != '\t'){
			
			if(text[i] >= '0' && text[i] <= '9'){
				token_num = token_num*10 + (text[i] - '0');
				b_num = true;
			}
			else{
				token_str += text[i];
				b_ch = true;
			}
		}
		if(!text[i+1] || text[i] == '\n' || text[i] == ' ' || text[i] == '\t'){
			proc(token_str.c_str(), token_num,
			     b_ch, b_num, str_f, num_f);
			b_ch = false;
			b_num = false;
			token_num = 0;
			token_str = "";
		}
		i++;
	}
	end();
}
