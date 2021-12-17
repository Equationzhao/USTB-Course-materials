//”Huffman.h”
#pragma once
#include <bitset>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;
struct Node {
    float freq;                       //频率
    int lchild;                       //左子树根节点的 id，没有则为-1
    int rchild;                       //右子树根节点的 id，没有则为-1
    int parent;                       //父节点的 id，没有则为-1
    bool isCandidate;                 //在构建根树时，每个结点只计算一次，该标志位为 true 时，表示该结点还没有进行过计算。
    string chr;//结点对应的字符，如果不是叶结点就置空
};
class Huffman {
public:
    Huffman();
    ~Huffman();
    /*
建立根树
输入， vector<string> vChrs：要传输的字符
输入， vector<float> vFreqs：每个字符出现的频率
输出， vector<Node>& vTrees：建立的树
*/
    void CreateHufTree(vector<string> vChrs, vector<float> vFreqs, vector<Node> &vTrees);
    /*
根据根树，生成霍夫曼编码
输入， const vector<Node>& vTrees：已经生成好的根树
输出， vector<string>& vHufCodes：得到的霍夫曼编码，次序与 CreateHufTree 函数
中字符出现的次序一致
*/
    void GenHufCode(const vector<Node> &vTrees, vector<string> &vHufCodes);
    /*
根据霍夫曼编码，对一个字符串进行编码
输入， const vector<string>& vChs：可能出现的字符
输入， const vector<string>& vHufCodes：对应的霍夫曼编码
输入， string strOrg：待编码的字符串
返回， 编码后的结果
*/
    string Code(const vector<string> &vChs, const vector<string> &vHufCodes, string strOrg);
    /*
根据霍夫曼编码的最优树，对一个字符串进行解码
输入， const vector<Node>& vTrees：霍夫曼编码的最优树
输入， string strCode：待解码的字符串
返回， 解码后的结果
*/
    string Decode(const vector<Node> &vTrees, string strCode);
    /*
根据霍夫曼编码，遍历码表，对一个字符串进行解码
输入， const vector<string>& vChs：可能出现的字符
输入， const vector<string>& vHufCodes：对应的霍夫曼编码
输入， string strCode：待解码的字符串
返回， 解码后的结果
*/
    string Decode(const vector<string> &vChs, const vector<string> &vHufCodes, string strCode);
    /*
打印霍夫曼编码
输入， const vector<string>& vChs：可能出现的字符
输入， const vector<string>& vHufCodes：对应的霍夫曼编码
*/
    void PrintHufCode(const vector<string> &vChs, const vector<string> &vHufCodes);
    /*
在一个 Node 序列中，找到频率最小的结点
输入， const vector<Node>& vNodes：序列
返回， 返回序列中频率最小结点的 id，如果序列为空，返回-1
*/
    int FindMin(const vector<Node> &vNodes);
};
