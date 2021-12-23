
#include "hashtable.h"
#include "dict.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cctype>
int read_from_file(FILE * input_file, Dict *d);
string findNextWord(FILE *input_file);
int main(int argc, char *argv[]) {
	if (argc != 2) {
		exit(1);
	}
	FILE *input = fopen(argv[1], "r");
	if (input == 0) {
		perror("Fopen Failed ");
		exit(-1);
	}
	Dict d = Dict();
	read_from_file(input, &d);
	fclose(input);
	d.print();
	return 0;
}

int read_from_file(FILE * input_file, Dict *d) {
	//TODO
	string s;
	while (1) {
		s = findNextWord(input_file);
		if (s.empty()) break;
		d->insert(s.c_str());
	}
	return 0;
}
string findNextWord(FILE *input_file) {
	//若返回的string为空，则代表文件结束
	string s;
	char c;
	while ((c = fgetc(input_file)) != EOF) {
		/*
		//单词为空的情况下读取到任何非字母字符
		if ((!isalpha(c)) && s.empty()) continue;
		//正常读取到一个单词
		if (!isalnum(c)&& !s.empty()) break;
		//正常读取中，遇到数字
		if ((c >= '0'&&c <= '9')) {
			s.clear();
			continue;
		}
		//正常读取中，遇到特殊字符
		if (!isalpha(c)) {
			break;
		}
		//正常读取一个字符
		if (isalpha(c)) {
			s.push_back(tolower(c));
		}
		*/
		//考虑单词为空的所有情况
		if (isalpha(c)) {
			c = tolower(c);
		}
		if (s.empty()) {
			if (isalpha(c)) {
				s.push_back(c);
			}
			else continue;
		}
		//不为空
		else {
			if (isalpha(c)) {
				s.push_back(c);
			}
			else {
				break;
			}
		}
	}
	return s;

}
