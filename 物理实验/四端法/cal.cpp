#include <bits/stdc++.h>
using namespace std;

// aceppt paramaters from command line and calculate.
int main() {
    double sum (0);
    auto add = [&](double a) {
        sum += a;
    };


    vector<double> tokens;
    string line;
    //read string from command line and split by space
    while (getline(cin, line)) {
        stringstream ss(line);
        string token;

        while (getline(ss, token, ' ')) {
            tokens.push_back(stod(token));
        }
        line="";
    }


    //贝塞尔公式
    double Sigma(0);
    double res(0);
    for_each(tokens.begin(), tokens.end(), add);
    for (auto &&i : tokens)
    {   
        Sigma+=pow((i-sum/tokens.size()),2);
    }
    res=sqrt(Sigma/(tokens.size()-1));
            
    //不确定度
    constexpr double deltaIns = 0.004;
    double U_d = sqrt(pow(res,2)+pow(deltaIns,2));
    
    cout << res << endl;

    return 0;
}