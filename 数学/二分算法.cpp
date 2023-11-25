#include<bits/stdc++.h>
using namespace std;
double powr(double a,int n){//¿ìËÙÃÝ 
	double ans=1;
	while(n){
		if(n%2==1) ans=ans*a;
		a*=a;
		n/=2;
	}
	return ans;
}
double jisuan(double x){
	return 8*powr(x,4)+7*powr(x,3)+2*powr(x,2)
			+3*x+6;
}
int main()
{
	double x,y,Y,left,right;
	while(cin>>x>>y>>Y){
		left=x;
		right=y;
		while(right-left>1e-6){
			double mid=(left+right)/2;
			if(jisuan(mid)>Y){
				right=mid-1e-7;
			}else{
				left=mid-1e-7;
			}
		}
		printf("%.4f\n",(left+right)/2);
		cout<<jisuan((left+right)/2)<<endl;
	}
	
}
