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
#define eps 1e-6
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int t,n,m;
int vis[maxn],w[maxn];
int dp[maxn],Max[maxn],fa[maxn];
vector<int> G[maxn];
vector<int> fG[maxn];
vector<int> GG[maxn];//新建图 
stack<int> st;

void dfs1(int v){
	vis[v]=1;
	for(int i=0;i<G[v].size();i++){
		if(!vis[G[v][i]]) dfs1(G[v][i]);
	}
	st.push(v);
}

void dfs2(int v,int ff){
	vis[v]=1;
	fa[v]=ff;//缩点 
	Max[ff]=max(Max[ff],w[v]);
	for(int i=0;i<fG[v].size();i++){
		if(!vis[fG[v][i]]) dfs2(fG[v][i],ff);
	}
}

int dfs(int v){
	if(dp[v]) return dp[v];
	dp[v]=Max[v];//本身 
	for(int i=0;i<GG[v].size();i++){
		dp[v]=max(dp[v],dfs(GG[v][i]));
	}
	return dp[v];
}
int main()
{
//	std::ios::sync_with_stdio(false);
//    cin.tie(NULL);
//	cin>>t;
	scanf("%d",&t);
	while(t--){
//		cin>>n>>m;
		scanf("%d%d",&n,&m);
		while(!st.empty()) st.pop();
		for(int i=0;i<=n;i++){
			vis[i]=0; 
			G[i].clear();
			fG[i].clear();
			dp[i]=0,Max[i]=0;
			w[i]=0;
			GG[i].clear();
			fa[i]=i;
		}
		for(int i=1;i<=n;i++) scanf("%d",&w[i]);
		while(m--){
			int a,b;
//			cin>>a>>b;
			scanf("%d%d",&a,&b);
			G[a].push_back(b);
			fG[b].push_back(a);
		}
		
		for(int i=1;i<=n;i++){
			if(!vis[i]) dfs1(i);
		}
		
		memset(vis,0,sizeof(vis));
		
		while(!st.empty()){
			int v=st.top();
			st.pop();
			if(!vis[v]){
				dfs2(v,v);
			}
		}
		
		for(int i=1;i<=n;i++){   //建缩点后的图 
			for(int j=0;j<G[i].size();j++){
				if(fa[i]==fa[G[i][j]]) continue;
				
				GG[fa[i]].push_back(fa[G[i][j]]);//G[i][j]->fa[G[i][j]]    注意 
			}
		}
		
		for(int i=1;i<=n;i++){
			printf("%d\n",dfs(fa[i]));	
				
											//cout不关同步流时间很大
//			cout<<dfs(fa[i])<<endl;
			//if(i!=n) 
				//cout<<endl; 
		}
	
		
	}
}
