#include <stack>
#include <queue>
using namespace std;
int Compare_stack_queue(std::stack<int> *s, std::queue<int> *q);
int Compare_stack_queue(std::stack<int> *s, std::queue<int> *q) {
	//长度不等直接gg
	stack<int> s2,s3 = *s;
	//将s倒序存入s2
	while (!s3.empty()) {
		s2.push(s3.top());
		s3.pop();
	}
	s = &s2;
	if (s->size() != q->size()) return 0;
	//长度均为0，则完全一样
	if (s->size() == 0 && q->size() == 0) return 1;
	//复制一个栈，然后处理
	stack<int> s1(*s);
	queue<int> q1(*q);
	s1.pop();
	q1.pop();
	return Compare_stack_queue(&s1, &q1);
}