#include "state.h"
#include <iostream>
#include <climits>
#include <queue>
using namespace std;


//���еĸ��ƺ������ǰ�������������һ��
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

//��ͼ�е��ڽӱ�������һ����
void State::add_edge(int from,int to) {
	this->edge[from].push_back(to);
}

void State::parse(PNG *p) {
	//TODO
	//���Ȱ�ͼ�ϸ���������ݳ�ʼ����G��
	this->p = p;
	this->width = p->get_width();
	this->height = p->get_height();
	this->rows = height / 8;
	this->cols = width / 8;
	int r, g, b;
	int start_col = 4;  //��ʼ��λ��
	bool isOdd = true;

	int test_count = 0;

	for (int i = 1; i <= rows; i++) {
		if (isOdd) {
			isOdd = !isOdd;
			start_col = 4;  //�����д�4��ʼ
		}
		else {
			isOdd = !isOdd;
			start_col = 8;  // ż���д�8��ʼ
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
	//��G�е�����ת��Ϊһ���ڽӱ�
	for (int i = 1; i <= rows; i++) {
		for (int j = 1; j <= (i % 2 ? cols : cols - 1); j++) {
			
			if (i % 2 == 1) {
				num = i / 2 * cols + i/2*(cols-1) + j; // �����еı��
			}
			else {
				num = i/2 *cols + (i/2-1)*(cols-1) + j;  // ż���еı��
			}

			industry[num] = G[i][j];        // �ѹ�ҵ��չֵ��industry
			// ��������ڵ����������ߣ������Ͽ�ʼ˳ʱ�����δ���
			// ������Ҫ��ϸ��������ͼƬ�����俼�Ǳ߽�����
			// ����ͼƬһ���� ������ ����ĩβ
			// ���ȴ���������
			if (i % 2) {
				if (i != 1&&j!=1) add_edge(num, num - cols);
				if (i != 1&&j!=cols) add_edge(num, num - cols + 1);
				if (j != cols) add_edge(num, num + 1);
				if (j != cols && i != rows) add_edge(num, num + cols);
				if (j != 1 && i != rows) add_edge(num, num + cols - 1);
				if (j != 1) add_edge(num, num - 1);
			}
			//����ż����
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

	// ������Ϣ
	/*for (int i = 1; i <= last_num; i++) {
		cout << i << " : " << industry[i] << endl;
	}(/
	/*
	int test = 60;
	cout <<test<< "�Žڵ��Industry�ǣ�" << industry[test] << endl;
	cout << "��֮���ڵĽڵ��У�" << endl;
	for (int i = 0; i < edge[test].size(); i++) {
		cout << edge[test][i] << " ";
	}
	cout << endl;
	//system("pause");
	*/
	return bfs(1,last_num);
}

int d[MAXN];  //��̾���
int State::bfs(int s,int t) {
	//ͨ��bfs�����s��t����̾���
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