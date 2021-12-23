#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX_SIZE 200

class Player_info {
private:
	std::string username;
	int score;
	long uid;
public:
	Player_info();
	~Player_info();
	Player_info(Player_info &other);
	Player_info(std::string in_name, long in_uid, int in_score);
	Player_info &operator=(Player_info &other);
	int get_score() const;
	const std::string &get_name() const;
	bool operator==(Player_info &other) const;
	bool operator!=(Player_info &other) const;
	bool operator<(Player_info &other) const;
	bool operator<=(Player_info &other) const;
	bool operator>(Player_info &other) const;
	bool operator>=(Player_info &other) const;
	void print();
};

// 这是个小根堆
class Heap {
private:
	Player_info *arr;  //用户堆，利用数组存储
	//std::vector<Player_info> arr;
	int num;             // 用户数目

	void heapify_up();
	void heapify_down();
	int get_child(bool direction, int index);
	int get_father(int index);
public:
	~Heap();
	Heap();
	Heap(Heap &other);
	Heap &operator=(Heap &other);
	int get_num() const;
	int insert(Player_info &p);
	Player_info *sort();
	void print();
};

#endif
