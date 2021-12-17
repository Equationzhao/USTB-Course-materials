
//以下是 main 函数
#include "TruthTable.h"
using namespace std;
int main() {
    TruthTable tt;
    tt.Print("Q|(P|R)&!S");
    tt.Print("Q|P");
    return 0;
}