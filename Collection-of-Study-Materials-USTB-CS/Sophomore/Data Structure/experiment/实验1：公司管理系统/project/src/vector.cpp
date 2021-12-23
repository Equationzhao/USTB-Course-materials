#include "vector.h"
#include "worker.h"
#include <string>
#include <iostream>
#include <cstdlib>
/*提示：这里的 data 是一个指向指针的指针。
在操作指针前请三思！
如果你不知道的话：malloc 的功能和 new 类似，
这里使用 malloc 是为了方便空间不足时进行扩展。
不用担心，扩展函数已为你写好。
－－前一位实习生
*/
/*
TODO 实现 insert 函数：在数组内插入新的 worker。
如果数组满了调用 expand()，返回 1
其他情况执行插入，返回 0
*/
int vector::insert(Worker *new_worker) {
	if (length > size-1) {
		expand();
		*(data + length) = new_worker;
		length++;
		return 1;
	}
	*(data + length) = new_worker;
	length++;
	return 0;
}

//TODO get 函数的功能不言自明。你可以自行处理非法输入，但是绝不能容许内存错误。
Worker *vector::get(int index) {
	if(index>=length) return NULL;
	return *(data + index);
}

//TODO
Worker *vector::remove(int index) {
	if (index >= length) return NULL;
	Worker *temp = *(data + index);
	for (int i = index; i < length - 1; i++) {
		*(data + i) = *(data + i + 1);
	}
	length--;
	return temp;
}

/*以下内容不建议修改。*/

vector::~vector() {
	for (int i = 0; i < length; i++) {
		delete *(data + i);
	}
	free(data);
}

vector::vector(int input_size) {
	size = input_size;
	length = 0;
	data = (Worker **)calloc(sizeof(Worker *), input_size);
}

void vector::expand() {
	size = size * 2;
	data = (Worker **)realloc(data, sizeof(Worker *) * size);
	return;
}

void vector::print() {
	std::cout << "Current vector:\n";
	for (int i = 0; i < length; i++) {
		std::cout << "[" << i << "] ";
		(*(data + i))->print();
	}
	std::cout << "Current vector Ends\n";
}

bool vector::isEmpty() {
	return !(length < 0);
}
