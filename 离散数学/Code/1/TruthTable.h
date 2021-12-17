#pragma once
#include <map>
#include <string>
#include <vector>
/*
    为了简化问题，设定：
    每个命题都用单个大写字母表示；
    !：否定
    &：合取
    |：析取
    -：蕴涵
    =：等价
*/
#ifndef __TRUTHTABLE
#define __TRUTHTABLE
class TruthTable {
public:
    TruthTable();
    ~TruthTable();
    /*
    获取合式公式的后缀表达式
    输入， std::string wff：输入的合式公式
    输出， std::string &suffix：合式公式的后缀表达式
    返回值，bool：成功返回 true，失败返回 false
    */
    bool GetSuffix(std::string wff, std::string &suffix);
    /*
    通过后缀表达式获取各层公式
    输入， std::string suffix：合式公式的后缀表达式
    输出， std::vector<std::string>& vPropsitions：按照计算次序，输出各层公式
    */
    void GetTableHead(std::string suffix, std::vector<std::string> &vPropsitions);
    /*
    通过后缀表达式获取各层公式的值
    输入， std::string suffix：合式公式的后缀表达式
    输入， std::map<char, bool> std::mapAlphabetVals：合式公式中，每个命题变元的取值
    输出， std::vector<bool>& vPropsitionVals：按照计算次序，输出各层公式的值
    返回， 返回整个合式公式的值
    */
    bool GetValueOfWFF(std::string suffix, std::map<char, bool> mapAlphabetVals, std::vector<bool> &vPropsitionVals);
    /*
    获取合式公式中所有的命题变元
    输入， std::string wff：输入的合式公式
    返回值，std::vector<char>：返回的命题变元列表
    */
    std::vector<char> GetAlphabet(std::string wff);

    /*
    对于一组赋值，求解一个合式公式的真值
    输入，std::string wff：输入的合式公式
    函数直接打印真值表
    返回，bool：该公式是否是一个合式公式
    */
    bool Print(std::string wff);

private:
    //运算符优先级，优先级越高，值越大
    std::map<char, int> m_mapConnectivePrior;

    /*
    计算一个联结词的真值，a 在前，b 在后
    输入，bool a：第一项的真值
    bool b：第二项的真值
    char connective：联结词
    返回，bool：合式公式的真值
    */
    bool CalcValueOfConnective(bool a, bool b, char connective);
};

#endif//