#ifndef STATE_H_
#define STATE_H_
#include "suan_png.h"
#include "pxl.h"
#include <set>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 1000;
class State {

public:
	int width;
	int height;
	int rows;
	int cols;
	int last_num;
	int G[MAXN][MAXN];
	vector<int>edge[MAXN];
	int industry[MAXN];
	PNG *p;
	State();
	State(State &other);
	State(State &&other);
	~State();
	State &operator=(State &&other);
	State &operator =(State &other);
	void add_edge(int from, int to);
	void parse(PNG *p);
	int solve();
	int bfs(int s,int t);
};


#endif
