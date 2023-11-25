/*
本题由于数据过大。 

利用母函数  和 泰勒公式 得到 （4^(n-1) + 2^(n-1))* x^n/n!
 

所以 4^(n-1) + 2^(n-1) 即为方案数 



*/


#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<cstdio>
using namespace std;
typedef  long long ll;
ll power(ll a,ll n){
	int ans=1;
	a%=100;
	while(n){
		if(n%2==1) ans=ans*a%100;
		a=(a*a)%100;
		n/=2;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,cnt;
	while(cin>>n,n){
		cnt=1;
		while(n--){
			ll a;
			cin>>a;
			cout<<"Case "<<cnt<<": "<<(power(4,a-1)+power(2,a-1))%100<<endl;
			cnt++;
		}
		cout<<endl;
	} 
}

