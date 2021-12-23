#ifndef STACK_CPP
#define STACK_CPP

#include "stack.h"
#include <iostream>

//首先实现Node类
template<class T> Node<T>::Node()
{
	//生成一个空的Node
	next = NULL;
	ptr = NULL;
}

//使用引用的构造函数
template<class T> Node<T>::Node(Node &other)
{
	//根据另一个引用生成新的Node
	//首先需要复制一个T元素,再将ptr指向新的T元素
	next = NULL;
	ptr = new T(*(other.ptr));
}

//重载等于号
template<class T>
Node<T> &Node<T>::operator=(Node<T> &other)
{
	//深度复制
	//但是考虑将相同元素赋值给自己的情况
	if (&other != this)
	{
		next = NULL;
		ptr = new T(*(other.ptr));
		return *this;
	}

	else
	{
		return *this;
	}
}

//根据T指针的构造函数
template<class T> Node<T>::Node(T *t)
{
	ptr = t;
	next = NULL;
}

//析构函数
template <class T> Node<T>::~Node()
{
	if (ptr != NULL)
	{
		delete ptr;
	}
}

//设置下一个元素
template <class T>
void Node<T>::set_next(Node<T> *n)
{
	next = n;
	return;
}

template <class T>
Node<T> *Node<T>::get_next() const
{
	return next;
}

//打印Node信息
template <class T>
void Node<T>::print()
{
	std::cout << "[" << *ptr << "]->";
	return;
}


//接下来Stack
template<class T> Stack<T>::Stack()
{
	length = 0;
	top_ = NULL;
}

//引用复制
template<class T> Stack<T>::Stack(Stack<T> &other)
{
	length = other.length;

	if (other.top_ == NULL)
	{
		top_ = NULL;
	}

	else
	{
		top_ = new Node<T>(*(other.top_));
		copy(this->top_, other.top_);
	}
}

//重载等号
template <class T>
Stack<T> &Stack<T>::operator=(Stack<T> &other)
{
	length = other.length;

	if (&other == this)
	{
		return *this;
	}

	if (other.top_ == NULL)
	{
		top_ = NULL;
	}

	else
	{
		top_ = new Node<T>(*(other.top_));
		copy(this->top_, other.top_);
	}

	return *this;
}

//析构函数，从头开始删除
template <class T> Stack<T>::~Stack()
{
	remove(top_);

}

//获得栈顶元素
template <class T>
T *Stack<T>::top()
{
	// TODO
	if (get_size() == 0)
	{
		return NULL;
	}

	else
	{
		return top_->ptr;
	}
}

//判断栈是否为空
template<class T>
bool Stack<T>::isEmpty()
{
	return length == 0;
}

//压栈重载1 压入一个T元素的指针
template<class T>
void Stack<T>::push(T *t)
{
	//排除意外情况
	if (t == NULL)
	{
		return;
	}

	//否则创建一个新的T
	Node<T> *node = new Node<T>(new T(*t));
	//Node<T> *node = new Node<T>(t);
	node->set_next(top_);
	top_ = node;
	length++;
	return;
}

//压栈重载2 压入一个Node的指针
template<class T>
void Stack<T>::push(Node<T> *n)
{
	//排除空指针
	if (n == NULL)
	{
		return;
	}

	//创建一个新的T
	Node<T> *node = new Node<T>(*n);
	node->set_next(top_);
	top_ = node;
	length++;
}

//弹出栈顶元素
template<class T>
Node<T> *Stack<T>::pop()
{
	//排除空栈的情况
	if (this->get_size() == 0)
	{
		return NULL;
	}

	Node<T> *temp = top_;
	top_ = top_->get_next();
	length--;
	return temp;
}

template <class T>
int Stack<T>::get_size() const
{
	return length;
}

template <class T>
void Stack<T>::print() const
{
	Node<T> *p = top_;

	while (p != NULL)
	{
		p->print();
		p = p->get_next();
	}

	return;
}

//private 复制this other
template <class T>
void Stack<T>::copy(Node<T> *this_, Node<T> *other_)
{
	if (other_->get_next() == NULL)
	{
		return;
	}

	this_->set_next(new Node<T>(*(other_->get_next())));
	copy(this_->get_next(), other_->get_next());
	return;
}


//private 移除n及以后的元素
template <class T>
void Stack<T>::remove(Node<T> *n)
{
	if (n == NULL)
	{
		return;
	}

	if (n->get_next() == NULL)
	{
		delete n;
		return;
	}

	Node<T> *tmp = n->get_next();
	delete n;
	remove(tmp);
	return;
}

#endif // !STACK_CPP