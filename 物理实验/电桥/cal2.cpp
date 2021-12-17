#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{

	double N{atof(argv[1])},R0{atof(argv[2])},deltaD{atof(argv[3])},deltaR{atof(argv[4])};
	
	const auto f = 0.2;//等级指数
	//const auto f = 0.1;
	const auto RN = 100;
	auto S=R0*deltaD/(deltaR);  //灵敏度
	auto E=f/100*(N*R0+N*RN/10);//极限误差
	auto resS=N*R0*0.2/S;		//灵敏度带来的误差
	auto resURx=sqrt(E*E+resS*resS);//不确定度
	printf("%lf\n%lf\n%lf\n%lf\n",S,E,resS,resURx);

	return 0;
}
