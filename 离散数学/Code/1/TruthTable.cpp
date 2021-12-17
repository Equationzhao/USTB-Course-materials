//以下是 ”TruthTable.cpp”
#include "TruthTable.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <utility>
using namespace std;
TruthTable::TruthTable() {
    //建立运算符优先级顺序
    m_mapConnectivePrior.insert(pair<char, int>('=', 0));
    m_mapConnectivePrior.insert(pair<char, int>('-', 1));
    m_mapConnectivePrior.insert(pair<char, int>('|', 2));
    m_mapConnectivePrior.insert(pair<char, int>('&', 3));
    m_mapConnectivePrior.insert(pair<char, int>('!', 4));
    m_mapConnectivePrior.insert(pair<char, int>('(', -1));
}
TruthTable::~TruthTable() = default;
bool TruthTable::GetSuffix(string wff, string &suffix) {
    stack<char> cstack;//栈
    suffix = "";
    for (int i = 0; i < wff.size(); ++i) {
        if (wff[i] == '(' || wff[i] == '!')//左括号和否定直接入栈
        {
            cstack.push(wff[i]);
        } else if ((wff[i] >= 'A') && (wff[i] <= 'Z'))//如果是命题变元，就直接加入到后缀表达式中
        {
            suffix += wff[i];
        } else {
            //如果是其他符号，需要判定优先级。栈空就把符号入栈
            if (cstack.empty()) cstack.push(wff[i]);
            else {
                char topConn = cstack.top();
                //如果该符号不是右括号，且优先级低于栈顶符号，则将栈中比该符号优先级高的符号依次弹出，加入到后缀表达式，直至遇到左括号或者栈空为止。并将该符号入栈。
                if (wff[i] != ')' && m_mapConnectivePrior[wff[i]] <=
                                             m_mapConnectivePrior[topConn]) {
                    while (m_mapConnectivePrior[wff[i]] <=
                           m_mapConnectivePrior[topConn]) {
                        if (cstack.empty()) break;
                        topConn = cstack.top();
                        if (topConn == '(') break;
                        suffix += topConn;
                        cstack.pop();
                    }
                    cstack.push(wff[i]);
                } else if (wff[i] == ')')//如果是右括号，则将将栈中符号依次弹出，加入到后缀表达式，直至左括号为止。并将括号从栈中弹出
                {
                    while (true) {
                        if (cstack.empty()) return false;//如果直到栈空都没遇到左括号，说明不是合式公式
                        char stop = cstack.top();
                        cstack.pop();
                        if (stop == '(') {
                            break;
                        }
                        suffix += stop;
                    }
                } else//如果该符号优先级高于栈顶符号，将该符号入栈
                {
                    cstack.push(wff[i]);
                }
            }
        }
    }
    while (!cstack.empty())//将剩余符号都弹出，但是如果有左括号，说明不是合式公式
    {
        suffix += cstack.top();
        if (cstack.top() == '(') return false;
        cstack.pop();
    }
    return true;
}
void TruthTable::GetTableHead(string suffix, vector<string> &vPropsitions) {
    vPropsitions.clear();
    stack<string> sstack;
    //用后缀表达式计算各层公式
    for (int j = 0; j < suffix.size(); ++j) {
        //命题就进栈
        if ((suffix[j] >= 'A') && (suffix[j] <= 'Z')) {
            sstack.push(string("") + suffix[j]);
        } else//遇到联结词，就计算栈顶的结果，并将计算的真值入栈
        {
            if (suffix[j] == '!') {
                string strX = sstack.top();
                sstack.pop();
                sstack.push("!(" + strX + ")");
                vPropsitions.push_back("!(" + strX + ")");
            } else {
                string strA = sstack.top();
                sstack.pop();
                string strB = sstack.top();
                sstack.pop();
                string strConnRes = "(" + strB + suffix[j] + strA + ")";//先进后出
                sstack.push(strConnRes);
                vPropsitions.push_back(strConnRes);
            }
        }
    }
}
bool TruthTable::GetValueOfWFF(string suffix, map<char, bool> mapAlphabetVals,
                               vector<bool> &vPropsitionVals) {
    vPropsitionVals.clear();
    stack<bool> bstack;
    //用后缀表达式计算真值
    for (int j = 0; j < suffix.size(); ++j) {
        //命题就进栈
        if ((suffix[j] >= 'A') && (suffix[j] <= 'Z')) {
            bstack.push(mapAlphabetVals[suffix[j]]);
        } else//遇到联结词，就计算栈顶的结果，并将计算的真值入栈
        {
            if (suffix[j] == '!') {
                bool x = bstack.top();
                bstack.pop();
                bstack.push(!x);
                vPropsitionVals.push_back(!x);
            } else {
                bool a = bstack.top();
                bstack.pop();
                bool b = bstack.top();
                bstack.pop();
                bool connRes = CalcValueOfConnective(b, a, suffix[j]);//先进后出
                bstack.push(connRes);
                vPropsitionVals.push_back(connRes);
            }
        }
    }
    bool res4oneWFF = bstack.top();
    bstack.pop();
    return res4oneWFF;
}
vector<char> TruthTable::GetAlphabet(string wff) {
    set<char> res;
    for (auto i:wff)
	{
        if ((i >= 'A') && (i <= 'Z')) {
            res.emplace(i);
        }
    }
	return {res.begin(), res.end()};
}

bool TruthTable::Print(string wff) {
    //获取所有变元
    vector<char> vAlphabets = GetAlphabet(wff);
    //获取后缀表达式
    string suffix = "";
    bool isSuffixSucess = GetSuffix(wff, suffix);
    if (!isSuffixSucess) return false;
    cout << "后缀表达式：" << suffix << '\n';
    //获取表头
    vector<string> vPropsitions;
    GetTableHead(suffix, vPropsitions);
    //遍历所有可能的取值
    int num = pow(2, vAlphabets.size());
    for (int i = 0; i < num; ++i) {
        int tmpnum = i;
        map<char, bool> mapAlphabetVals;
        vector<bool> vProppsitionVals;
        //逆序赋值，顺序打印，使得字母表按照二进制 0 到 n-1 的次序排列
        for (int j = vAlphabets.size() - 1; j > -1; j--) {
            mapAlphabetVals.insert(pair<char, bool>(vAlphabets[j], tmpnum % 2));
            tmpnum /= 2;
        }
        bool res4oneWFF = GetValueOfWFF(suffix, mapAlphabetVals, vProppsitionVals);
        //打印表头
        if (i == 0) {
            for (int j = 0; j < vAlphabets.size(); ++j) {
                cout << vAlphabets[j] << " ";
            }
            for (int j = 0; j < vPropsitions.size(); ++j) {
                cout << vPropsitions[j] << " ";
            }
            cout << wff << endl;
        }
        //打印本次真值
        //先打印字母表真值，再打印各层结果
        for (int j = 0; j < vAlphabets.size(); ++j) {
            cout << mapAlphabetVals[vAlphabets[j]] << " ";
        }
        for (int j = 0; j < vProppsitionVals.size(); ++j) {
            cout << vProppsitionVals[j];
            for (int k = 0; k < vPropsitions[j].size(); ++k) {
                cout << " ";
            }
        }
        cout << res4oneWFF << endl;
    }
    return true;
}
bool TruthTable::CalcValueOfConnective(bool a, bool b, char connective) {
    switch (connective) {
        case '&':
            return a && b;
        case '|':
            return a || b;
        case '-':
            return !a || b;
        case '=':
            return a == b;
        default:
            cout << "wrong connective" << endl;
            return false;
    }
}