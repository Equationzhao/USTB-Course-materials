#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
#include "stack.h"

template <class T>
class Queue {
private:
	//boffin TODO
	int length;
	Stack<T> *s1, *s2;
public:
	Queue();
	Queue(Queue &other);
	~Queue();
	Queue &operator=(Queue &other);
	int get_size() const;
	bool isEmpty() const;
	void push(T *t);
	void push(Node<T> *n);
	void s1_to_s2();
	void s2_to_s1();
	Node<T> *pop();
	void print();
};

#include "queue.cpp"
#endif
