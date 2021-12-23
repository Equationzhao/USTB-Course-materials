#ifndef TREE_H_
#define TREE_H_
#include <cstdint>
#include <cmath>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include "pxl.h"
#include "suan_png.h"
using namespace std;
class Node {
public:
	PNG *p; //the upper left pixel

	bool leaf; //是否是叶子节点，true 代表是叶子节点
	
	int mean_r; //Rmean
	int mean_g; //Gmean
	int mean_b; //Bmean
	int mean_alpha; //透明度平均值
	int cut_time;
	// 把children修改为公有成员
	Node **children; //pointer to four other node
	int width; //当前像素区块的宽度
	int height; //当前像素区块的高度
	int x; //当前像素区块左上角顶点像素的横坐标
	int y; //当前像素区块左上角顶点像素的纵坐标
    //后备的rgb
    int backup_r;
    int backup_g;
    int backup_b;
	Node();
	Node(PNG* corner, int input_width, int input_height, int x, int y);
	Node(Node &other);
	Node(Node &&other) noexcept;
	Node& operator=(Node &other);
	Node& operator=(Node &&other);
	~Node();
	void print();
	pxl *get_pxl();

};


class Tree {
public:
	Node *root; //根结点

	Tree();
	~Tree();
	Tree(Tree &other);
	Tree& operator=(Tree &other);
	void judge(int threshold);
	pxl *get_pxl();
	void load_png(PNG *png);
	void print();

	//extra===============
	// 初始化中计算平均数的函数
	void cal_average(Node *node);
	//judge的递归辅助函数
	void sub_judge(Node *node, int threshold);
	//求出该节点以下的所有 叶子 的r,g,b之和
	void cal_sum(Node *node,int &r_sum,int &g_sum,int &b_sum);  
	//辅助递归函数
	double cal_sum_var(Node* node, int &sum,int &mean_r,int &mean_g,int &mean_b);  
	//下降到最底层，计算一个节点的var
	//double cal_var(Node *node, int &mean_r,int &mean_g,int &mean_b);  
	//将node下所有叶节点的rgb设置为平均值
	int set_mean(Node *node,int r,int g,int b);
	//测试函数，将所有叶子赋值给像素块
	int set_all(Node *node);  
	//找到最大剪枝次数
	int max_cut_time(Node* node);
    //将所有叶子节点的mean_rgb设置回初始值
    int set_origin(Node* node);
};
#endif
