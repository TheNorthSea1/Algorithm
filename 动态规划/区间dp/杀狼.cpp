//杭电5115 

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
int dp[500][500];
int n;
int a[500],b[500];
int dfs(int L,int R){
	
	if(dp[L][R]!=inf) return dp[L][R];
	if(L-1==R) return 0;  //注意此处的特判情况 
	if(L==R+1) return 0;
	if(L==R) return a[L]+b[L-1]+b[L+1];
	
	for(int i=L;i<=R;i++){
		dp[L][R] = min( dp[L][R] , dfs(L,i-1) + dfs(i+1,R) + a[i] +b[L-1]+ b[R+1]);
	}
	
	return dp[L][R];
	
	
}
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin>>n;
	int cnt=0;
	while(n--){
		int t;
		cin>>t;
		ms(a,0),ms(b,0);
		for(int i=0;i<500;i++)
		for(int j=0;j<500;j++)
		dp[i][j]=inf;
		
		for(int i=1;i<=t;i++) cin>>a[i];
		for(int i=1;i<=t;i++) cin>>b[i];
		
		cnt++;
		cout<<"Case #"<<cnt<<": "<<dfs(1,t)<<endl;
		
	}
}

