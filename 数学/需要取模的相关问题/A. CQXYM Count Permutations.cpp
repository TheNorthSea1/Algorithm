//https://codeforces.com/contest/1581/problem/A 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn = 1e5 + 5;
const int mod = 1e9+7;
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	
	//看题猜结论时 （2n!)/2  
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll ans=1;
		for(int i=3;i<=2*n;i++){  //什么时候去除2 重点、 
			ans=(ans*i)%mod;
		}
		cout<<ans<<endl;
	}
	
	//不能得到答案后在除以2 是错误的  




}

