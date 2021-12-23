#include "heap.h"
#define LEFT true
#define RIGHT false

#define LIST_SIZE 2000

Heap::~Heap() {
	//TODO
    if(arr!=NULL)
	    delete[] arr;
	arr = NULL;
}

Heap::Heap(Heap &other) {
	//TODO
	//深度复制
	this->num = other.num;
	this->arr = new Player_info[LIST_SIZE];
	for (int i = 0; i < num; i++) {
		arr[i] = other.arr[i];
	}
}

Heap &Heap::operator=(Heap &other) {
	//TODO
	if (&other == this) {
		return *this;
	}
	this->num = other.num;
    delete[] this->arr;
	this->arr = new Player_info[LIST_SIZE];
	for (int i = 0; i < num; i++) {
		arr[i] = other.arr[i];
	}
	return *this;
}

void Heap::heapify_up() {
	//TODO
	// 自底向上堆化
	// 1.对于每个元素，寻找它的父亲
	// 2.若父亲比儿子大，则将他们两个交换
	// 最后一个元素的索引为 num-1

	// 首先处理空堆
	if (this->get_num() == 0) return;
	// 获取最后一个元素
	Player_info lastPlayer = arr[num - 1];  //获取排名最后的玩家
	int father, i;
	for (i = num - 1; i > 0; i = father) {
		father = this->get_father(i);
		if (lastPlayer < this->arr[father]) {
			this->arr[i] = this->arr[father];
		}
		else {
			break;
		}
	}
	this->arr[i] = lastPlayer;
	//std::cout << "向上堆化 ： 新元素 " << lastPlayer.get_score() << "放到" << i << std::endl;
	return;
}

void Heap::heapify_down() {
	//TODO
	// 自顶向下堆化
	// 将大元素和其儿子中较小的那个交换
	int i, child;
	// 排除空堆
	if (this->get_num() == 0) return;
	// 获得堆顶的玩家
	Player_info firstPlayer = this->arr[0];
	for (i = 0; i * 2 + 1 < this->get_num(); i = child) {
		// 找到较小的儿子玩家
		child = i * 2 + 1;
		if (child != this->get_num() - 1 && this->arr[child] > this->arr[child + 1]) {
			child++;
		}
		if (firstPlayer > this->arr[child]) arr[i] = this->arr[child];
		else break;
	}
	this->arr[i] = firstPlayer;
	//std::cout << "向下堆化 ： 新元素 " << firstPlayer.get_score() << "放到" << i << std::endl;
	return;
}

int Heap::get_child(bool direction, int index) {
	//TODO
	if (this->num == 0 || index >= this->num || this->num<0)	return -1;
	if (direction == LEFT) return 2 * index + 1;
	else return 2 * index + 2;
}

int Heap::get_father(int index) {
	//TODO
	if (this->num == 0 || index >= this->num || this->num <= 0) return -1;
	if (index % 2 == 1) return index / 2;
	else return index / 2 - 1;
}

int Heap::insert(Player_info &p) {
	//TODO
	// 如果堆满了，就自顶向下堆化
	// 如果没满，就插入到最后，再自底向上堆化
	if (this->num >= LIST_SIZE) {
		if (p < this->arr[0]) {
			return 1;
		}
		else {
			this->arr[0] = p;
			this->heapify_down();
			return 0;
		}
	}
	else {
		this->arr[this->num++] = p;
		this->heapify_up();
		return 0;
	}
}

void Qsort(Player_info *a, int left, int right) {
	int i = left, j = right;
	Player_info pivot = a[left];
	if (i >= j) return;
	while (i < j) {
		while (i < j&&pivot >= a[j]) j--;
		if (i < j) {
			a[i] = a[j];
			i++;
		}
		while (i < j&&pivot <= a[i]) i++;
		if (i < j) {
			a[j] = a[i];
			j--;
		}
	}
	a[i] = pivot;
	Qsort(a, left, i - 1);
	Qsort(a, i + 1, right);
	return;
}

Player_info *Heap::sort() {
	//TODO
	if (this->num == 0) return NULL;
	//冒泡排序
	// 首先复制arr
	Player_info *a = new Player_info[LIST_SIZE+10];
	//Player_info a[LIST_SIZE];
	for (int i = 0; i<LIST_SIZE; i++) {
		a[i] = this->arr[i];
	}
	//冒泡-并不能行
	/*
	 for(int i=0;i<LIST_SIZE;i++){
	     for(int j=0;j<LIST_SIZE-1;j++){
	         if(a[j]<a[j+1]){
	             Player_info t = a[j+1];
	             a[j+1] = a[j];
	             a[j] = t;
	         }
	     }
	 }
	 */
	//快排
	Qsort(a, 0, this->get_num()-1);
	return a;
}

/*
=========================================================
================ WARNING ===== 警告 ======================
===Please Do Not Modify Any of the Following Functions===
===================请不要修改以下函数=======================
=========================================================
*/

int Heap::get_num() const {
	return num;
}

Heap::Heap() {
	num = 0;
	arr = new Player_info[LIST_SIZE];
}

void Heap::print() {
	for (int i = 0; i < num; i++) {
		arr[i].print();
	}
	printf("\nSize of the heap is %d\n", num);
}

Player_info::Player_info() {
	username = std::string("#");
	uid = 0;
	score = 0;
}

Player_info::~Player_info() {

}

Player_info::Player_info(Player_info &other) {
	username = std::string((other.username));
	score = other.score;
	uid = other.uid;
}

Player_info::Player_info(std::string in_name, long in_uid, int in_score) {
	username = std::string(in_name);
	score = in_score;
	uid = in_uid;
}

Player_info &Player_info::operator=(Player_info &other) {
	username = std::string((other.username));
	score = other.score;
	uid = other.uid;
	return *this;
}

int Player_info::get_score() const {
	return score;
}

const std::string &Player_info::get_name() const {
	return username;
}

bool Player_info::operator==(Player_info &other) const {
	if (score == other.score) {
		return true;
	}
	return false;
}

bool Player_info::operator!=(Player_info &other) const {
	if (score == other.score) {
		return false;
	}
	return true;
}

bool Player_info::operator<(Player_info &other) const {
	if (score < other.score) {
		return true;
	}
	return false;
}

bool Player_info::operator<=(Player_info &other) const {
	if (score <= other.score) {
		return true;
	}
	return false;
}

bool Player_info::operator>(Player_info &other) const {
	if (score > other.score) {
		return true;
	}
	return false;
}

bool Player_info::operator>=(Player_info &other) const {
	if (score >= other.score) {
		return true;
	}
	return false;
}

void Player_info::print() {
	printf("[%ld]%s - %d\n", uid, username.c_str(), score);
	return;
}
