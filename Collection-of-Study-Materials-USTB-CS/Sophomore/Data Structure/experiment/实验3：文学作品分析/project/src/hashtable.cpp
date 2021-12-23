#include "hashtable.h"

bool Node::operator!=(const char *str) {
	//和C风格字符串比较
	if (str == NULL) return false;
	string s(str);
	if (p.first != s) return true;
	return false;
}

bool Node::operator!=(const string &str) {
	//和string比较
	if (p.first != str) return true;
	return false;
}

bool Node::operator==(const char *str) {
	//TODO
	if (str == NULL) return false;
	string s(str);
	return p.first == s;
}

bool Node::operator==(const string &str) {
	return p.first == str;
}

bool Node::operator!=(Node &n) {
	return n.p.first != this->p.first;
}

bool Node::operator==(Node &n) {
	return n.p.first == this->p.first;
}

char Node::operator[](const int index) {
	return p.first[index];
}

int Node::length() { //return length of the string
	return p.first.size();
}

int &Node::second() {
	return p.second;
}

const pair<string, int>* Node::get_pair() const {
	//返回一个p的指针
	const pair<string, int>* psi = &p;
	return psi;
}

Node::~Node() {
	//Node的析构函数，需要清理Node的所有内存
}

HashTable::HashTable() {
	//哈希表的构造函数
	val = new int[MAXN];
	for (int j = 0; j < MAXN; j++) {
		val[j] = 0;
		elem.push_back(Node());
	}
	size = MAXN;
}

HashTable::~HashTable() {
	//哈希的析构函数，删掉给Node和val分配的内存
	delete[]val;
}

int HashTable::hash(Node &index) {
	//哈希函数，将Node转化为一个整数
	//计算方式：默认全部为小写，取'a'=0,'z'=25，计算前4位的位权和（不足4位则全取）
	int length = index.length();
	char c = tolower(index.get_pair()->first[0]);
	int ans = c * 300 % MAXN;
	/*for (int i = 0; i < length && i < 3; i++) {
	ans *= (tolower(index.get_pair()->first[i]) - 'a' + 1);
	}*/

	return ans%MAXN;
}

bool HashTable::search(Node &index, int &pos, int &times) {
	//在表中查找index，如果查找到，返回true；否则返回false
	//如果查找到index，pos即记为它的位置，否则记为遇到的第一个空位置
	//time记为冲突发生次数
	int hashCode = hash(index);
	pos = hashCode;
	times = 0;
	for (int i = hashCode%MAXN; times<2 * MAXN; i = (i + 1) % MAXN) {
		if (val[i] && elem[i] == index) {
			//匹配到
			pos = i;
			return true;
		}
		else if (!val[i]) {
			pos = i;
			return false;
		}
		else {
			times++;
		}
	}
	pos = -1;
	return false;
}

int HashTable::insert(Node &index) {
	//TODO
	int pos, times;
	if (search(index, pos, times)) {
		elem[pos].second()++;
		return 2;
	}
	else {
		elem[pos] = index;
		elem[pos].second() = 1;
		val[pos] = 1;
		return 1;
	}

}

int HashTable::insert(const char * str) {
	//TODO
	Node a(str);
	return insert(a);
}

/*
==========================================================================
=================Please Do Not Modify Functions Below=====================
========================请不要修改下列函数实现================================
==========================================================================
*/

Node::Node() {
	p = make_pair(string("#"), 1);
}

Node::Node(const char *str) {
	p = make_pair(string(str), 1);
}

Node::Node(const string &str) {
	p = make_pair(str, 1);
}

int HashTable::get_size() const {
	return size;
}

const pair<string, int>* HashTable::get_pair(int index) {
	if (index < size && index >= 0) {
		return (elem[index].get_pair());
	}
	return NULL;
}

const pair<string, int>* HashTable::get_pair(int index) const {
	if (index < size && index >= 0) {
		return (elem[index].get_pair());
	}
	return NULL;
}
