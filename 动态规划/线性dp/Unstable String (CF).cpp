/*
https://codeforces.com/problemset/problem/1535/C





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
const int maxn=3e5+5;
//ll dp[maxn][2];//dp[i][0] 表示到  i点  以0为结尾时的最多合法子序列。 
				// dp[i][1]  表示到  i点  以1为结尾时的最多合法子序列。
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		ll dp[s.size()][2];
		ll ans=1;
		if(s[0]=='1'){    //初始化dp 
			dp[0][1]=1;
			dp[0][0]=0;
		}else if(s[0]=='0'){
			dp[0][0]=1;
			dp[0][1]=0;
		}else{
			dp[0][0]=dp[0][1]=1;
		}
		
		for(int i=1;i<s.size();i++){
			if(s[i]=='?'){
				dp[i][1]=dp[i-1][0]+1;
				dp[i][0]=dp[i-1][1]+1;
			}else{
				if(s[i]=='0'){
					dp[i][0]=dp[i-1][1]+1;
					dp[i][1]=0;
				}else{
					dp[i][1]=dp[i-1][0]+1;
					dp[i][0]=0;
				}
			}
			
			ans+=max(dp[i][0],dp[i][1]);
		}
		
		cout<<ans<<endl;
	}
	
	
	
	
	
}
