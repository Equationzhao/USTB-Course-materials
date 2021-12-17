//“TopologicalSort.h”
#pragma once
#ifndef __TOPOLOGICALSORT
#define __TOPOLOGICALSORT
class TopologicalSort {
public:
    TopologicalSort() = default;
    ~TopologicalSort();
    int *m_piMatrix{nullptr};//用于表示图的邻接矩阵，N*N，ij 相邻则为 1，否则为 0
    int *m_ipRes{nullptr};   //排序结果
    int m_iN;                //结点数
    //int* matrix 的数据需要在类外进行释放
    void setGraphMatrix(int *matrix, int N);
    //拓扑排序，如果有环返回 false
    //没有环，则排序正确，返回 true，并将结果存储到 m_ipRes 里
    bool getOrder();
    void printRes();
};

#endif
