#include "tree.h"
/*
PNG *p; //the upper left pixel
Node **children; //pointer to four other node
int width; //当前像素区块的宽度
int height; //当前像素区块的高度
bool leaf; //是否是叶子节点，true 代表是叶子节点
int x; //当前像素区块左上角顶点像素的横坐标
int y; //当前像素区块左上角顶点像素的纵坐标
int mean_r; //Rmean
int mean_g; //Gmean
int mean_b; //Bmean
*/
Node::Node() {
	//TODO
	//为两个指针分配内存空间
	p = NULL;
	this->children = new Node*[4];
	for (int i = 0; i < 4; i++) {
		this->children[i] = NULL;
	}
	//将剩下的数值初始化
	this->width = 0;
	this->height = 0;
	this->leaf = false;
	this->x = 0;
	this->y = 0;
	this->mean_b = 0;
	this->mean_g = 0;
	this->mean_r = 0;
	cut_time = 0;
}

Node::Node(PNG* corner, int input_width, int input_height, int x, int y) {
	//TODO
	this->p = corner;
	this->children = new Node*[4];
	for (int i = 0; i < 4; i++) {
		this->children[i] = NULL;
	}
	this->width = input_width;
	this->height = input_height;
	this->leaf = (input_width == 1 && input_height == 1);
	this->x = x;
	this->y = y;
	this->mean_r = get_pxl()->red;
	this->mean_g = get_pxl()->green;
	this->mean_b = get_pxl()->blue;
    this->backup_r = this->mean_r;
    this->backup_g = this->mean_g;
    this->backup_b = this->mean_b;
	cut_time = 0;
}

Node::Node(Node &other) {
	//TODO
	this->p = new PNG();
	*p = *(other.p);
	this->children = new Node*[4];
	for (int i = 0; i < 4; i++) {
		this->children[i] = other.children[i];
	}
	this->width = other.width;
	this->height = other.height;
	this->leaf = other.leaf;
	this->x = other.x;
	this->y = other.y;
	this->mean_r = other.mean_r;
	this->mean_g = other.mean_g;
	this->mean_b = other.mean_b;
	cut_time = 0;
}

Node::Node(Node &&other) noexcept {
	//释放资源
	//delete this->p;
	//delete[] this->children;
	//接管资源
	this->p = other.p;
	this->children = other.children;
	this->width = other.width;
	this->height = other.height;
	this->leaf = other.leaf;
	this->x = other.x;
	this->y = other.y;
	this->mean_r = other.mean_r;
	this->mean_g = other.mean_g;
	this->mean_b = other.mean_b;
	this->cut_time = other.cut_time;
	//释放资源
	other.p = nullptr;
	other.children = nullptr;
}

Node& Node::operator=(Node &other) {
	//TODO
	//检测自赋值
	if (this == &other) return *this;
	//不用开辟新空间，直接复制
	p = (other.p);
	for (int i = 0; i < 4; i++) {
		this->children[i] = other.children[i];
	}
	this->width = other.width;
	this->height = other.height;
	this->leaf = other.leaf;
	this->x = other.x;
	this->y = other.y;
	this->mean_r = other.mean_r;
	this->mean_g = other.mean_g;
	this->mean_b = other.mean_b;
	this->cut_time = other.cut_time;
	return *this;
}

Node& Node::operator=(Node &&other) {
	//TODO
	//TODO
	//检测自赋值
	if (this == &other) return *this;
	//释放已有资源
	if (p != NULL) delete p;
	if (children != NULL) delete[] children;
	//接管资源
	this->p = other.p;
	this->children = other.children;
	this->width = other.width;
	this->height = other.height;
	this->leaf = other.leaf;
	this->x = other.x;
	this->y = other.y;
	this->mean_r = other.mean_r;
	this->mean_g = other.mean_g;
	this->mean_b = other.mean_b;
	this->cut_time = other.cut_time;
	//将other变为可以析构的状态
	other.p = nullptr;
	other.children = nullptr;
	return *this;
}

void Tree::load_png(PNG *png) {
	root->p = png;
	root->width = png->get_width();
	root->height = png->get_height();
	root->x = 0;
	root->y = 0;
	root->leaf = (root->width == 1) && (root->height == 1);
	/*root->mean_b = root->get_pxl()->blue;
	root->mean_g = root->get_pxl()->green;
	root->mean_r = root->get_pxl()->red;*/
	queue<Node*> q;
	q.push(root);
	while (!q.empty()) {
		Node* b = q.front();
		q.pop();
		//给出四个分块的高度和宽度以及坐标位置
		int w[4], h[4], x[4], y[4];
		w[0] = w[2] = b->width / 2;
		w[1] = w[3] = b->width - b->width / 2;
		h[0] = h[1] = b->height / 2;
		h[2] = h[3] = b->height - b->height / 2;
		x[0] = x[2] = b->x; x[1] = x[3] = b->x + w[0];
		y[0] = y[1] = b->y; y[2] = y[3] = b->y + h[0];
		// 2.0
		/*w[0] = w[2] = b->width - b->width / 2;
		w[1] = w[3] = b->width / 2;
		h[0] = h[1] = b->height - b->height / 2;
		h[2] = h[3] = b->height / 2;
		x[0] = x[2] = b->x; x[1] = x[3] = b->x + w[0];
		y[0] = y[1] = b->y; y[2] = y[3] = b->y + h[0];*/
		// 分块长宽若都是1，那就是一个最终子块
		// 长宽若出现0，则舍去
		// 其它情况继续入队分解
		for (int i = 0; i < 4; i++) {
			if (w[i] == 1 && h[i] == 1) {
				b->children[i] = new Node(png, w[i], h[i], x[i], y[i]);
			}
			else if (w[i] == 0 || h[i] == 0) {
				continue;
			}
			else {
				b->children[i] = new Node(png, w[i], h[i], x[i], y[i]);
				q.push(b->children[i]);
			}
		}
	}

	//建队完毕，开始递归计算平均值
	cal_average(root);
}

//递归初始化每个节点的平均值
void Tree::cal_average(Node *node) {
	if (node->leaf) return;
	int valid_children = 0, sum_r = 0, sum_g = 0, sum_b = 0;
	for (int i = 0; i < 4; i++) {
		if (node->children[i] != NULL) {
			valid_children++;
			cal_average(node->children[i]);
			sum_r += node->children[i]->mean_r;
			sum_g += node->children[i]->mean_g;
			sum_b += node->children[i]->mean_b;
		}
	}
	node->mean_r = sum_r / valid_children;
	node->mean_g = sum_g / valid_children;
	node->mean_b = sum_b / valid_children;
}

void Tree::judge(int threshold) {
	//TODO
    if (this->root == NULL) {
		return;
	}
	sub_judge(root, threshold);
    set_origin(root);
    cal_average(root);
	return;
}

void Tree::sub_judge(Node *node, int threshold) {
	int valid_children = 0;
	if (node->leaf == true) return;
	//首先对四个子节点进行“处理”
	for (int i = 0; i < 4; i++) {
		if (node->children[i] != NULL) {
			sub_judge(node->children[i], threshold);
			valid_children++;
		}
	}
	//判断能否剪枝
	/*for (int i = 0; i < 4; i++) {
	if (node->children[i] != NULL) {
	node->cut_time = max(node->cut_time, node->children[i]->cut_time);
	}
	}*/
	node->cut_time = max_cut_time(node);
	if (node->cut_time > 2) {
		return;
	}

	int sum_r = 0, sum_g = 0, sum_b = 0;
	int mean_r, mean_g, mean_b;
	int var_sum = 0, var;
	//计算出均值之和，再求均值
	cal_sum(node, sum_r, sum_g, sum_b);

	node->mean_r = mean_r = sum_r / valid_children;
	node->mean_g = mean_g = sum_g / valid_children;
	node->mean_b = mean_b = sum_b / valid_children;
	//cout << mean_r << "   " << mean_g << "   " << mean_b << endl;

	//计算方差
	cal_sum_var(node, var_sum, mean_r, mean_g, mean_b);
	var = var_sum / (30 * valid_children);
	//若方差小于threshold，就将所有叶子节点的像素设置为均值，同时改变他们的mean
	if (var < threshold) {
		set_mean(node, mean_r, mean_g, mean_b);
	}
}


void Tree::cal_sum(Node *node, int &r_sum, int &g_sum, int &b_sum) {
	for (int i = 0; i < 4; i++) {
		if (node->children[i] != NULL) {
			r_sum += node->children[i]->mean_r;
			g_sum += node->children[i]->mean_g;
			b_sum += node->children[i]->mean_b;
		}
	}
}

int Tree::set_mean(Node *node, int r, int g, int b) {
	if (node == NULL) return -1;
    node->mean_r = r;
    node->mean_g = g;
    node->mean_b = b;
	if (node->leaf == true) {
		node->cut_time++;
		node->get_pxl()->blue = node->mean_b;
		node->get_pxl()->red = node->mean_r;
		node->get_pxl()->green = node->mean_g;
		return 0;
	}
	for (int i = 0; i < 4; i++) {
		if (node->children[i] != NULL) {
			set_mean(node->children[i], r, g, b);
			node->cut_time = max(node->cut_time, node->children[i]->cut_time);
		}
	}
	return 1;
}

//计算下一层的方差之和
double Tree::cal_sum_var(Node* node, int &sum, int &mean_r, int &mean_g, int &mean_b) {
	for (int i = 0; i < 4; i++) {
		if (node->children[i] != NULL) {
			Node *child = node->children[i];
			sum += (child->mean_r - mean_r)*(child->mean_r - mean_r) + (child->mean_g - mean_g)*(child->mean_g - mean_g) + (child->mean_b - mean_b)*(child->mean_b - mean_b);
		}
	}
	return 0.0;
}

int Tree::set_all(Node* node) {
	if (node == NULL) return -1;
	if (node->leaf == true) {
		node->get_pxl()->blue = node->mean_b;
		node->get_pxl()->red = node->mean_r;
		node->get_pxl()->green = node->mean_g;
		return 0;
	}
	for (int i = 0; i < 4; i++) {
		if (node->children[i] != NULL) {
			set_all(node->children[i]);
		}
	}
	return 1;
}

int Tree::set_origin(Node* node) {
	if (node == NULL) return -1;
	if (node->leaf == true) {
		node->mean_b = node->backup_b;
		node->mean_r = node->backup_r;
		node->mean_g = node->backup_g;
		return 0;
	}
	for (int i = 0; i < 4; i++) {
		if (node->children[i] != NULL) {
			set_origin(node->children[i]);
		}
	}
	return 1;
}

int Tree::max_cut_time(Node* node) {
	if (node->leaf) return node->cut_time;
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (node->children[i] != NULL) {
			ans = max(ans, max_cut_time(node->children[i]));
		}
	}
	return ans;
}

/*
================================================
====DO NOT MODIFY ANY OF THE FUNCTIONS BELOW====
==============请不要修改以下任何函数================
================================================
*/

Node::~Node() {
	for (int i = 0; i < 4; i++) {
		if (children[i] != NULL) {
			delete children[i];
		}
	}
	delete[] children;
}

void Node::print() {
	if (children[0] != NULL) {
		children[0]->print();
	}
	if (children[1] != NULL) {
		children[1]->print();
	}
	if (children[2] != NULL) {
		children[2]->print();
	}
	if (children[3] != NULL) {
		children[3]->print();
	}
	printf("Red: %u, Green: %u, Blue: %u, Width: %d, Height: %d\n", mean_r, mean_g, mean_b, width, height);
	//printf("Red: %u, Green: %u, Blue: %u, Width: %d, Height: %d,", get_pxl()->red, get_pxl()->green, get_pxl()->blue, width, height);
	std::cout << "Leaf: " << leaf << std::endl;
	return;
}

pxl* Node::get_pxl() {
	return p->get_pxl(x, y);
}

Tree::Tree() {
	root = new Node();
}

Tree::~Tree() {
	delete root;
}

Tree::Tree(Tree &other) {
	if (other.root != NULL) {
		root = new Node(*other.root);
	}
}

Tree& Tree::operator=(Tree &other) {
	if (other.root != NULL && &other != this) {
		root = new Node(*(other.root));
	}
	return *this;
}

pxl *Tree::get_pxl() {
	return root->get_pxl();
}

void Tree::print() {
	root->print();
}
