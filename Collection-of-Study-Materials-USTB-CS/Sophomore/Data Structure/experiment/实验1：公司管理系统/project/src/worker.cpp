#include "worker.h"
#include <string>
#include <iostream>

/*TODO 实现一个构造函数。
Worker 的名字已经被分配在堆(Heap)上*/
Worker::Worker(std::string &input_name) {
	name = input_name;
	id = num_worker;
	num_worker++;
}

/*TODO 实现一个 get 函数。
返回该 worker 的 id*/
int Worker::get_id() {
	return id;
	return 0;
}

/*TODO 实现一个 get 函数。
返回该 worker 的 Name*/
std::string &Worker::get_name() {
	return name;
}


/*预警：以下内容不许修改。*/
int Worker::num_worker = 0;                  //警告：你不可以改动这一行！

Worker::Worker() {                            //警告：你不可以改动这个函数！
	this->id = num_worker;
	num_worker++;
	this->name = std::string("default_string");

}

Worker::~Worker() {                           //警告：你不可以改动这个函数！
}

int Worker::print() {
	std::cout << "Worker [" << this->id << "] with name [" << (this->name) << "]\n";
	return 0;
}
