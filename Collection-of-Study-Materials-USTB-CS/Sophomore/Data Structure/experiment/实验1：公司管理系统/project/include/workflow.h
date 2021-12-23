/*
@file /include/workflow.h
*/
#ifndef WORKFLOW_H
#define WORKFLOW_H
#include <memory>
#include "worker.h"
#include "vector.h"

class Job {
private:
	static int num_job;
	int id;
public:
	Worker *worker;
	Job *next;
	Job *prev;
	Job();
	~Job();                                           //TODO
	int print();
};

class Workflow {
private:
	int size;
public:
	Job *head;
	Job *tail;
	Workflow();                                       //TODO
	~Workflow();                                      //TODO
	int insert(Job *j);                               //TODO
	int swap(int original_index, int target_index);   //TODO
	Job *pop();                                       //TODO
	int process(vector *l, int index);                //TODO
	int print();
	//下面是标准链表的一些操作
	int isEmpty();
	int isHead(Job *j);
	int isLast(Job *j);
	Job *nodeDelete(int index);                       //返回删除的节点
	//Job *nodeInsert(int index, Job *j);             //返回Job *j
	Job *findIndex(int index);                        //根据index返回元素指针
	bool sswap(Job *&a, Job *&b);
};
#endif

