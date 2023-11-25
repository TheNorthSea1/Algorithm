/*
https://codeforces.com/contest/1592/problem/C






*/ 

#include<bits/stdc++.h>
#define ms(__x__,__val__) memset(__x__, __val__, sizeof(__x__))
#define FI(__x__,__y__) for(int i=__x__;i<__y__;i++)
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn = 1e5 + 5;
const int mod = 1e9+7;
int n,k;
int sum;//为所有节点的异或和 

int cntnum;//计入有几个部分的异或和为sum 

vector<int> G[maxn];
int a[maxn];//储存每个节点的值 

int val[maxn];//val[i] i点到这个分量的异或和

void dfs(int cur,int fa){
	val[cur] = a[cur];
	
	for(auto u:G[cur]){
		if(u==fa) continue;
		
		dfs(u,cur);
		
		val[cur] ^= val[u];	
	}
	
	if(val[cur] == sum){  // 找出与sum相等的 连通块。 
		cntnum++;
		
		val[cur] = 0;//�ص� �˴������и�重点 此处进行
	}
	return;
} 
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;

		sum=0;
		cntnum=0;

		FI(0,n+1){
			G[i].clear();
			a[i]=0;
			val[i]=0;
		} 
		
		FI(1,n+1) cin>>a[i],sum^=a[i];
		FI(0,n-1){
			int x,y;
			cin>>x>>y;
			
			G[x].push_back(y);
			G[y].push_back(x);
		}
		int ok=0;
		
		if(!sum) ok=1;//如果sum=0，那么删一条边就行;
		else{
			dfs(1,0);
			if(cntnum>=3 && k>=3) ok=1; //
		} 
		if(ok) puts("YES");
		else puts("NO");
		
	}








	return 0;



}

