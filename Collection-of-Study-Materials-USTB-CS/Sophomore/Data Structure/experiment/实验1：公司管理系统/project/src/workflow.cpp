#include "workflow.h"
#include "worker.h"
#include "vector.h"
#include <iostream>

Job::~Job() {
	//TODO
	if(worker!=NULL) delete worker;
}

Workflow::Workflow() {
	//TODO
	size = 0;
	head = NULL;
	tail = NULL;
}

//删除链表
Workflow::~Workflow() {
	Job *j;
	while (head != NULL) {
		j = head;
		head = head->next;
		delete j;
	}
}

//在末尾插入元素
int Workflow::insert(Job *j) {
	//排除j为空的情形
	if (j == NULL) return 1;
	//判断链表是否为空
	if (isEmpty()) {
		head = j;
		tail = j;
	}
	else {
		tail->next = j;
		j->prev = tail;
		tail = j;
	}
	size++;
	return 0;
}

bool Workflow::sswap(Job *&a, Job *&b) {
	Job *tmp = a;
	a = b;
	b = tmp;
	return true;
}

//交换链表的元素，更改对应位置及其前后的链接
int Workflow::swap(int original_index, int target_index) {
	//保证original在前
	if (original_index > target_index)
		return swap(target_index, original_index);
	//避免相等的错误
	if (original_index == target_index)
		return 0;

	//判断坐标的错误
	if (original_index >= size || original_index < 0 || target_index >= size || original_index < 0) {
		return 1;
	}

	Job *a, *b,*temp;
	a = findIndex(original_index);
	b = findIndex(target_index);
	//b是尾结点的情形
	if (b->next == NULL) {
		tail = a;
		//a不是头结点的情形
		if (a->prev != NULL) {
			//a,b相邻
			if (a->next == b) {
				//与尾节点相邻的交换
				b->next = a;
				b->prev = a->prev;
				a->next = NULL;
				a->prev->next = b;
				a->prev = b;
			}
			//a,b不相邻
			else {
				//与尾节点不相邻的代换
				b->next = a->next;
				b->prev->next = a;
				temp = b->prev;
				b->prev = a->prev;
				a->next->prev = b;
				a->next = NULL;
				a->prev->next = b;
				a->prev = temp;
			}
		}
		//a是头结点，且b是尾节点的情形的情形
		else {
			head = b;
			//a,b相邻(只有两个元素)
			if (a->next == b) {
				//头、尾节点的交换
				b->next = a;
				a->prev = b;
				a->next = NULL;
				b->prev = NULL;
			}
			//a,b不相邻
			else {
				a->next->prev = b;
				b->prev->next = a;
				a->prev = b->prev;
				b->next = a->next;
				a->next = NULL;
				b->prev = NULL;
			}
		}
	}
	//b不是尾节点
	else {
		//a不是头结点的情形
		if (a->prev != NULL) {
			//a,b相邻
			if (a->next == b) {
				a->prev->next = b;
				b->next->prev = a;
				a->next = b->next;
				b->prev = a->prev;
				a->prev = b;
				b->next = a;
			}
			//a,b不相邻
			else {
				sswap(a->next->prev, b->next->prev);
				sswap(a->prev->next, b->prev->next);
				sswap(a->next, b->next);
				sswap(a->prev, b->prev);
			}
		}
		//a是头结点，b不是尾节点
		else {
			head = b;
			//a,b相邻
			if (a->next == b) {
				b->next->prev = a;
				a->next = b->next;
				b->next = a;
				a->prev = b;
				b->prev = NULL;
			}
			//a,b不相邻
			else {
				a->next->prev = b;
				b->prev->next = a;
				b->next->prev = a;
				sswap(a->next, b->next);
				a->prev = b->prev;
				b->prev = NULL;
			}
		}
	}
	return 0;
}

//从头部弹出元素
Job *Workflow::pop() {
	return nodeDelete(0);
}
/*
用列表中第一个工人处理任务
1.工人离开工人列表
2.检查工作是否有人做
3.如果有，删除正在工作的工人，工作的worker指针指向新的工人
4.如果没有，直接修改worker指针指向新的工人
*/
int Workflow::process(vector *l, int index) {
	if (l == NULL) {
		return 1;
	}
	Worker *w = l->remove(0);
	if(index > size || index < 0||w == NULL) {
		return 1;
	}
	
	Job *j = findIndex(index);
	if (j->worker != NULL) {
		delete j->worker;
		j->worker = w;
	}
	else {
		j->worker = w;
	}
	
	return 0;
}

int Workflow::isEmpty() {
	if (head == NULL) return 1;
	else return 0;
}

int Workflow::isHead(Job* j) {
	return j == head;
}

int Workflow::isLast(Job* j) {
	return j == tail;
}
//移除节点，但不释放内存空间
Job *Workflow::nodeDelete(int index) {
	//超出限制
	if (index >= size) return NULL; 
	Job *pre, *nxt, *cur = head;
	int i = 0;
	while (i < index) {
		cur = cur->next;
		i++;
	}
	pre = cur->prev;
	nxt = cur->next;
	if (!isHead(cur)) {
		pre->next = nxt;
	}
	else {
		head = nxt;
	}
	if (!isLast(cur)) {
		nxt->prev = pre;
	}
	else {
		tail = pre;
	}
	size--;
	return cur;
}


Job *Workflow::findIndex(int index) {
	if (index >= size) return NULL;
	Job *cur = head;
	int i = 0;
	while (i < index) {
		cur = cur->next;
		i++;
	}
	return cur;
}

/*预警：以下内容不许修改。*/
int Job::num_job = 0;   //Do not remove or modify this line.
						//警告：你不可以改动这一行！
Job::Job() {               //警告：你不可以改动这个函数！
	id = num_job;
	num_job++;
	next = NULL;
	prev = NULL;
	worker = NULL;
}
int Workflow::print() {     //警告：你不可以改动这个函数！
	Job * curr = head;
	int i = 0;
	if (curr == NULL) {
		std::cout << "Empty Flow\n";
		return 0;
	}
	while (curr != NULL) {
		std::cout << "[" << i << "]";
		curr->print();
		i++;
		curr = curr->next;
	}
	return 0;
}
int Job::print() {
	std::cout << "job [" << this->id << "]\n";
	return 0;
}