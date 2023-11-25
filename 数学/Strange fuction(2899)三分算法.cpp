#include<iostream>
#include<cmath>
using namespace std;
int Y;
const double eps=1e-6;
double f(double x){
	double sum=6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-Y*x;
	return sum;
}
int main()
{
	int n;
	while(cin>>n){
		while(n--){
			cin>>Y;
		double left=0;
		double right=100;
		while(right-left>eps){
			double thleft=left+(right-left)/3;
			double thright=right-(right-left)/3;
			if(f(thleft)>f(thright)){
				left=thleft;
			}else{
				right=thright;
			}
		}
		printf("%.4f\n",f(left));
//		printf("%.4f\n",f(right));
		}
	}
 } 
