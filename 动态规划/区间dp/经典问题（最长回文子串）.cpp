//https://vjudge.ppsucxtt.cn/problem/51Nod-1088
#include<bits/stdc++.h>
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
#define Fi(__x__,__y__) for(int i=__x__;i<__y__;i++)
#define Fj(__x__,__y__) for(int j=__x__;j<__y__;j++)
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn = 1e5 + 5;

template<class T>inline void read(T &res){
	char c;T flag=1;
	while( (c=getchar())<'0'||c>'9' ) if(c=='-')flag=-1;res=c-'0';
	while( (c=getchar())>='0'&&c<='9' ) res=res*10+c-'0';res*=flag;
}
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	string s;
	 
	while(cin>>s){
	int dp[s.size()+2][s.size()+2];  //表示 i 到 j 是否为回文串 
	ms(dp,0);
	
	for(int i=0;i<=s.size();i++) dp[i][i] = 1;
	
	
	int ans=0;
	for(int len=2;len<=s.size();len++){
		for(int i=0;i<s.size();i++){
			int j=i+len-1;
			if(j>=s.size()) break;
			
			if(len==2){  //注意长度为 2 时的情况-------徐特殊处理 
				if(s[i]==s[j]) dp[i][j]=1,ans=2; 
				continue;
			}
			if(s[i]==s[j]){
				dp[i][j]=dp[i+1][j-1];
				
				
				//注意此处需要当 i~j 为回文串才能更新 
				if(dp[i][j]) ans=len;
			}else{
				dp[i][j]=0;
			}
		}
	}

	cout<<ans<<endl;
	}

}

