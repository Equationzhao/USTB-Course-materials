#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "queue.h"
#include <iostream>

//这次使用两个栈来实现队列
//s1的栈底为队首
//s2的栈底为队尾
template<class T> Queue<T>::Queue()
{
	s1 = new Stack<T>();
	s2 = new Stack<T>();
	length = 0;
}

//直接复制s1,s2和length
template<class T> Queue<T>::Queue(Queue &other)
{
	this->length = other.get_size();
	s1 = new Stack<T>(*(other.s1));
	s2 = new Stack<T>(*(other.s2));
}

template<class T> Queue<T>::~Queue()
{
	delete s1;
	delete s2;
	length = 0;
}

template<class T>
Queue<T> &Queue<T>::operator=(Queue &other)
{
	if (&other == this)
	{
		return *this;
	}

	this->length = other->length;
	this->s1 = new Stack<T>(other.s1);
	this->s2 = new Stack<T>(other.s2);
	return *this;
}

template<class T>
int Queue<T>::get_size()const
{
	return length;
}

template<class T>
bool Queue<T>::isEmpty()const
{
	return length==0;
}

//这里可能出现内存泄漏
template<class T>
void Queue<T>::s1_to_s2()
{
	Node<T> *node;

	while (!s1->isEmpty())
	{
		node = s1->pop();
		s2->push(node);
		delete node;
	}
}

template<class T>
void Queue<T>::s2_to_s1()
{
	Node<T> *node;

	while (!s2->isEmpty())
	{
		node = s2->pop();
		s1->push(node);
		delete node;
	}
}

//压栈重载1
template<class T>
void Queue<T>::push(T *t)
{
	if (t == NULL)
	{
		return;
	}

	//深度复制一个节点
	//Node<T> *node = new Node<T>(new T(*t));
	//将s2中所有元素弹到s1中，之后在s1压入新节点
	s2_to_s1();
	s1->push(t);
	length++;
}

//压栈重载2
template<class T>
void Queue<T>::push(Node<T> *n)
{
	if (n == NULL)
	{
		return;
	}

	//将s2中所有元素弹到s1中，之后在s1压入新节点
	s2_to_s1();
	s1->push(n);
	length++;
}

//弹出
template<class T>
Node<T> *Queue<T>::pop()
{
	s1_to_s2();
	length--;
	return s2->pop();
}

//打印函数
template <class T>
void Queue<T>::print()
{
	s2_to_s1();
	s1->print();
	std::cout << "END" << std::endl;
	return;
}

#endif // !QUEUE_CPP