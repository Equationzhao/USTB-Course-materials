#include "stack.h"
#include "queue.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

Stack<std::string> *history;

Stack<std::string> *tmp;

int resume();
int undo();


//重做指令，将tmp的第一
int resume() {
	//如果两个指针尚未初始化，则初始化两个指针
	if (history == NULL) {
		history = new Stack<std::string>();
	}
	if (tmp == NULL) {
		tmp = new Stack<std::string>();
	}
	//排除tmp为空栈的情况
	if (tmp->get_size() == 0) {
		return 1;
	}
	history->push(tmp->pop());
	return 0;
}

//重做函数，将history的第一个元素弹出，存放入tmp
int undo() {
	//如果两个指针尚未初始化，则初始化两个指针
	if (history == NULL) {
		history = new Stack<std::string>();
	}
	if (tmp == NULL) {
		tmp = new Stack<std::string>();
	}
	//排除history为空栈的情况
	if (history->get_size() == 0) {
		return 1;
	}
	tmp->push(history->pop());
	return 0;
}
