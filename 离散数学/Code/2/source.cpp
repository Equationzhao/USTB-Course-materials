
//main 函数
#include "TopologicalSort.h"

int main() {
    TopologicalSort ts;
    int matrix[] =
            {
                    0, 0, 1, 1, 0, 0, 0, 0,
                    1, 0, 0, 0, 1, 1, 0, 0,
                    0, 0, 0, 0, 1, 0, 1, 0,
                    0, 0, 0, 0, 0, 1, 1, 0,
                    0, 0, 0, 0, 0, 0, 0, 1,
                    0, 0, 0, 0, 0, 0, 0, 1,
                    0, 0, 0, 0, 0, 0, 0, 1,
                    0, 0, 0, 0, 0, 0, 0, 0
            };
    int N = 8;
    ts.setGraphMatrix(matrix, N);
    if (ts.getOrder()) {
        ts.printRes();
    }
    return 0;
}