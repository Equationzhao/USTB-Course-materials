#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
		double r0{atof(argv[1])},r1{atof(argv[2])},deltaR{atof(argv[3])};
			
		auto s = r0*0.2/deltaR;//电桥灵敏度
		auto rs=0.2*r0/s;	   //灵敏度引起的测量误差
		auto res= (0.001*r0+0.0005*5);//仪器误差

		auto U0=sqrt(pow(res,2)+pow(rs,2));//R0 引起的不确定度

		cout
			<<s<<'\n'
			<<res<<'\n'
			<<rs<<'\n';
			

		auto rx =sqrt(r0*r1);
		cout<<U0/r0*sqrt(0.5)<<'\n'//Rx的相对不确定度
			<<rx<<"\n\n";
	

}

