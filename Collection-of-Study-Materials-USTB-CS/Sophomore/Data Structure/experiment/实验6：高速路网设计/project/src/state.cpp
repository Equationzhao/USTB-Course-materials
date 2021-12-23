#include "state.h"
#include <iostream>
#include <climits>
#include <queue>
using namespace std;


//所有的复制函数就是把所有向量复制一遍
State::State() {
	//TODO

}

State::State(State &other) {
	//TODO
	width = other.width;
	height = other.height;
	rows = other.rows;
	cols = other.cols;
	last_num = other.last_num;
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			G[i][j] = other.G[i][j];
		}
	}
	for (int i = 0; i < MAXN; i++) {
		edge[i] = other.edge[i];
	}
	for (int i = 0; i < MAXN; i++) {
		industry[i] = other.industry[i];
	}
	p = other.p;
	return;
}

State::State(State &&other) {
	//TODO
	width = other.width;
	height = other.height;
	rows = other.rows;
	cols = other.cols;
	last_num = other.last_num;
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			G[i][j] = other.G[i][j];
		}
	}
	for (int i = 0; i < MAXN; i++) {
		edge[i] = other.edge[i];
	}
	for (int i = 0; i < MAXN; i++) {
		industry[i] = other.industry[i];
	}
	p = other.p;
	other.p = nullptr;
}

State::~State() {
	//TODO
}

State &State::operator=(State &other) {
	//TODO
	width = other.width;
	height = other.height;
	rows = other.rows;
	cols = other.cols;
	last_num = other.last_num;
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			G[i][j] = other.G[i][j];
		}
	}
	for (int i = 0; i < MAXN; i++) {
		edge[i] = other.edge[i];
	}
	for (int i = 0; i < MAXN; i++) {
		industry[i] = other.industry[i];
	}
	p = other.p;
	return *this;
}

State &State::operator=(State &&other) {
	//TODO
	width = other.width;
	height = other.height;
	rows = other.rows;
	cols = other.cols;
	last_num = other.last_num;
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			G[i][j] = other.G[i][j];
		}
	}
	for (int i = 0; i < MAXN; i++) {
		edge[i] = other.edge[i];
	}
	for (int i = 0; i < MAXN; i++) {
		industry[i] = other.industry[i];
	}
	p = other.p;
	other.p = nullptr;
	return *this;
}

//给图中的邻接表上增加一条边
void State::add_edge(int from,int to) {
	this->edge[from].push_back(to);
}

void State::parse(PNG *p) {
	//TODO
	//首先把图上各个点的数据初始化到G中
	this->p = p;
	this->width = p->get_width();
	this->height = p->get_height();
	this->rows = height / 8;
	this->cols = width / 8;
	int r, g, b;
	int start_col = 4;  //初始行位置
	bool isOdd = true;

	int test_count = 0;

	for (int i = 1; i <= rows; i++) {
		if (isOdd) {
			isOdd = !isOdd;
			start_col = 4;  //奇数行从4开始
		}
		else {
			isOdd = !isOdd;
			start_col = 8;  // 偶数行从8开始
		}
		for (int j = 1; j <= cols&& start_col + (j - 1) * 8< width; j++) {
			test_count++;
			pxl *pix = p->get_pxl(start_col+(j-1)*8, 8 * i - 2);
			r = pix->red;
			g = pix->green;
			b = pix->blue;
			G[i][j] = 255 * 255 * 3 - r*r - g*g - b*b;
			//cout << G[i][j] << " ";
		}
		//cout << endl;
	}
	int num;
	//将G中的数据转化为一个邻接表
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= (i % 2 ? cols : cols - 1); j++) {
			
			if (i % 2 == 1) {
				num = i / 2 * cols + i/2*(cols-1) + j; // 奇数行的编号
			}
			else {
				num = i/2 *cols + (i/2-1)*(cols-1) + j;  // 偶数行的编号
			}

			industry[num] = G[i][j];        // 把工业发展值给industry
			// 获得其相邻的至多六个边，从左上开始顺时针依次处理
			// 这里需要仔细分析整个图片，尤其考虑边界条件
			// 所有图片一定是 奇数行 顶到末尾
			// 首先处理奇数行
			if (i % 2) {
				if (i != 1&&j!=1) add_edge(num, num - cols);
				if (i != 1&&j!=cols) add_edge(num, num - cols + 1);
				if (j != cols) add_edge(num, num + 1);
				if (j != cols && i != rows) add_edge(num, num + cols);
				if (j != 1 && i != rows) add_edge(num, num + cols - 1);
				if (j != 1) add_edge(num, num - 1);
			}
			//处理偶数行
			else {
				add_edge(num, num - cols);
				add_edge(num, num - cols + 1);
				if (j != cols-1) add_edge(num, num + 1);
				if (i != rows) add_edge(num, num + cols);
				if (i != rows) add_edge(num, num + cols - 1);
				if (j != 1) add_edge(num, num - 1);
			}
		}
	}
	this->last_num = num;
	return;
}

int State::solve() {
	//TODO

	// 调试信息
	/*for (int i = 1; i <= last_num; i++) {
		cout << i << " : " << industry[i] << endl;
	}(/
	/*
	int test = 60;
	cout <<test<< "号节点的Industry是：" << industry[test] << endl;
	cout << "与之相邻的节点有：" << endl;
	for (int i = 0; i < edge[test].size(); i++) {
		cout << edge[test][i] << " ";
	}
	cout << endl;
	//system("pause");
	*/
	return bfs(1,last_num);
}

int d[MAXN];  //最短距离
int State::bfs(int s,int t) {
	//通过bfs求出从s到t的最短距离
	for (int i = 0; i < MAXN; i++) {
		d[i] = 1e9;
	}
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < edge[cur].size(); i++) {
			int to = edge[cur][i];
			if (d[to] > d[cur] + industry[to]) {
				d[to] = d[cur] + industry[to];
				q.push(to);
			}
		}
	}
	return d[t];
}