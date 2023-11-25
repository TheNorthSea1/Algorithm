/*
https://pintia.cn/problem-sets/994805260223102976/problems/994805282389999616



这题与牛客里的 子序列题目类似
https://ac.nowcoder.com/acm/problem/220328 

*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<cstdio>
#define test(a) cout << "-----" << a << "-----" << '\n'
#define ms(__x__,__val__) memset(__x__, __val__, sizeof(__x__))
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn=1e5+5;
const ll mod=1e9+7;
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	string s;
	cin>>s;
	ll Pnum=0;
	ll sum=0;
	ll ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='P'){
			Pnum++;
		}else if(s[i]=='A'){
			sum=sum+Pnum;
		}else if(s[i]=='T'){
			ans=(ans+sum)%mod;
				
		}
	}
	cout<<ans<<endl;	
	
}
//TPATPPAAT

