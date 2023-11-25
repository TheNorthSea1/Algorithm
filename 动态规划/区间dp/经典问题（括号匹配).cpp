//https://vjudge.ppsucxtt.cn/problem/HRBUST-1834
//经典问题---括号匹配 
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
string s;
ll dp[105][105]; 
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	while(cin>>s){
		ms(dp,0);
		int n=s.size();
		for(int len=2;len<=n;len++){  //区间长度
		 
			for(int i=0;i<n;i++){  //枚举起点 
				int j=i+len-1;
				if(j>n-1) break;
				for(int k=i;k<=j;k++){  //枚举分割点 
					if((s[i]=='('&&s[k]==')')||(s[i]=='['&&s[k]==']'))
							dp[i][j]=max(dp[i][j],dp[i+1][k-1]+dp[k+1][j]+1);
					else
							dp[i][j]=max(dp[i][j],dp[i+1][k-1]+dp[k+1][j]);		
				}
			}
		}
		
		cout<<dp[0][s.size()-1]*2<<endl; 
	} 
	 
	 	 
	 
	 
}
