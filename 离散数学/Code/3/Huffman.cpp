//”Huffman.cpp”
#include "Huffman.h"
Huffman::Huffman() {
}
Huffman::~Huffman() {
}
void Huffman::CreateHufTree(vector<string> vChrs, vector<float> vFreqs, vector<Node> &vTrees) {
    //前 n 个节点是叶节点，父结点在此之后添加
    for (int i = 0; i < vFreqs.size(); ++i) {
        Node n;
        n.freq = vFreqs[i];
        n.lchild = -1;
        n.rchild = -1;
        n.parent = -1;
        n.isCandidate = true;
        n.chr = vChrs[i];
        vTrees.push_back(n);
    }
    //不断寻找值最小的两个结点相加，构成新的父结点，直至所有节点计算完毕
    while (true) {
        int minId1 = FindMin(vTrees);
        if (minId1 == -1) {
            break;//所有节点都已计算完毕
        } else {
            vTrees[minId1].isCandidate = false;
            int minId2 = FindMin(vTrees);
            if (minId2 == -1) {
                break;//minId1 是根节点，所有计算已完毕
            } else {
                vTrees[minId2].isCandidate = false;
                //最小的两个节点相加，生成新的父节点
                Node parent;
                parent.freq = vTrees[minId1].freq + vTrees[minId2].freq;
                parent.lchild = minId1;//最小值的结点总是作为左孩子
                parent.rchild = minId2;
                parent.parent = -1;//根节点的值为-1
                parent.isCandidate = true;
                parent.chr = "";
                vTrees.push_back(parent);
                vTrees[minId1].parent = vTrees.size() - 1;
                vTrees[minId2].parent = vTrees.size() - 1;
            }
        }
    }
}
void Huffman::GenHufCode(const vector<Node> &vTrees, vector<string> &vHufCodes) {
    for (int i = 0; i < vTrees.size(); ++i) {
        string code = "";
        if (vTrees[i].lchild == -1)//遍历所有叶节点（只有前 n 个才是叶节点）
        {
            //遍历父节点，直到根节点
            int pid = vTrees[i].parent;
            int cid = i;
            while (pid != -1) {
                //左子树为 0，右子树为 1。程序是从树叶到树根，因此需要逆序添加。
                if (vTrees[pid].lchild == cid) code = "0" + code;
                else
                    code = "1" + code;
                cid = pid;
                pid = vTrees[pid].parent;
            }
            vHufCodes.push_back(code);
        } else {
            break;
        }
    }
}
string Huffman::Code(const vector<string> &vChs, const vector<string> &vHufCodes, string strOrg) {
    string res = "";
    string strCh = "";
    map<string, string> ch2huf;
    //创建字符与霍夫曼编码的映射
    for (int i = 0; i < vChs.size(); ++i) {
        ch2huf.insert(pair<string, string>(vChs[i], vHufCodes[i]));
    }
    //将字符换成霍夫曼编码
    for (int i = 0; i < strOrg.length(); ++i) {
        res += ch2huf[string("") + strOrg[i]];
    }
    return res;
}
string Huffman::Decode(const vector<string> &vChs, const vector<string> &vHufCodes,
                       string strCode) {
    string res = "";
    string strCh = "";
    //一个个编码读入
    for (int i = 0; i < strCode.length(); ++i) {
        strCh += strCode[i];
        //由于是前缀码，当一个编码能够转换为一个字符时，转换即可，否则继续读入编码
        for (int j = 0; j < vHufCodes.size(); ++j) {
            if (strCh == vHufCodes[j]) {
                res += vChs[j];
                strCh = "";
                break;
            }
        }
    }
    return res;
}
string Huffman::Decode(const vector<Node> &vTrees, string strCode) {
    string res = "";
    string strCh = "";
    int id = vTrees.size() - 1;//根节点，从根结点遍历到叶结点
    //依次获取编码
    for (int i = 0; i < strCode.size(); ++i) {
        //0 左，1 右
        if (strCode[i] == '0') {
            id = vTrees[id].lchild;
        } else {
            id = vTrees[id].rchild;
        }
        if (vTrees[id].lchild == -1)//如果是叶结点，即解码成功，下一次重新从根结点开始搜索
        {
            res += vTrees[id].chr;
            id = vTrees.size() - 1;
        }
    }
    return res;
}
void Huffman::PrintHufCode(const vector<string> &vChs, const vector<string> &vHufCodes) {
    for (int i = 0; i < vChs.size(); ++i) {
        cout << vChs[i] << ": " << vHufCodes[i] << endl;
    }
}
int Huffman::FindMin(const vector<Node> &vNodes) {
    if (vNodes.size() == 0) return -1;
    float minv = FLT_MAX;
    int id = -1;
    for (int i = 0; i < vNodes.size(); ++i) {
        if (vNodes[i].isCandidate && minv > vNodes[i].freq) {
            minv = vNodes[i].freq;
            id = i;
        }
    }
    return id;
}