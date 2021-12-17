
//main 函数
#include "Huffman.h"
#include <iostream>
using namespace std;
int main() {
    vector<float> vFreqs{2, 3, 5, 7, 100};
    vector<string> vChs{"x", "w", "j", "D", "M"};
    vector<Node> vTrees;
    vector<string> vHufCodes;
    string str = "xwjDM"; // Discrete Mathematics
    string strCode;
    Huffman hfm;
    hfm.CreateHufTree(vChs, vFreqs, vTrees);
    hfm.GenHufCode(vTrees, vHufCodes);
    strCode = hfm.Code(vChs, vHufCodes, str);
    string strDecode = hfm.Decode(vChs, vHufCodes, strCode);
    string strDecode2 = hfm.Decode(vTrees, strCode);
    hfm.PrintHufCode(vChs, vHufCodes);
    cout << "编码前：" << str << endl;
    cout << "ASCII：";
    for (int i = 0; i < str.length(); ++i) {
        bitset<8> strBit(str[i]);//转换为二进制输出
        cout << strBit << " ";
    }
    cout << endl;
    cout << "编码后：" << strCode << endl;
    cout << "解码后：" << strDecode2 << endl;
    return 0;
}