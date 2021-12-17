//“TopologicalSort.cpp”
#include "TopologicalSort.h"
#include <iostream>
using namespace std;

TopologicalSort::~TopologicalSort() {
    delete[] m_ipRes;
}

void TopologicalSort::setGraphMatrix(int *matrix, int N) {
    m_piMatrix = matrix;
    m_iN = N;
    if (m_ipRes != nullptr) delete[] m_ipRes;
    m_ipRes = new int[N];
}
bool TopologicalSort::getOrder() {
    //对矩阵的每列求和，得到入度
    int *pIndegree = new int[m_iN];
    for (int j = 0; j < m_iN; ++j) {
        pIndegree[j] = 0;
        for (int i = 0; i < m_iN; ++i) {
            pIndegree[j] += m_piMatrix[i * m_iN + j];
        }
    }
    int resid = 0;
    while (resid < m_iN) {
        //入度为 0 的点放入到结果队列中
        bool isNoZero = true;
        for (int i = 0; i < m_iN; ++i) {
            if (pIndegree[i] == 0) {
                isNoZero = false;
                m_ipRes[resid++] = i;
                pIndegree[i] = -1;//该点从列表中删除
                //所有从该点可达的点，入度减一
                for (int j = 0; j < m_iN; ++j) {
                    if (m_piMatrix[i * m_iN + j] == 1) {
                        pIndegree[j]--;
                    }
                }
            }
        }
        //如果没有任何一个结点的入度为 0，且还有结点没有排序，说明有环
        if (isNoZero && resid < m_iN) {
            cout << "There is a cycle in the graph!" << endl;
            delete[] pIndegree;
            return false;
        }
    }
    delete[] pIndegree;
    return true;
}

void TopologicalSort::printRes() {
    for (int i = 0; i < m_iN; ++i) {
        cout << m_ipRes[i] << " ";
    }
    cout << endl;
}