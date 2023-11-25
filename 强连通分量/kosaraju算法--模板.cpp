#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cstdio>
#define test(a) cout << "-----" << a << "-----" << '\n'
#define eps 1e-6
using namespace std;
typedef long long ll;
int n,m;//表示n个点，和m条边。
int vis[100];
struct Node{
	int pos;
	Node(int pos): pos(pos){}
}; 
vector<Node> G[100];//原图 
vector<Node> fG[100];//反图
stack<int> st;

//获得点的顺序 
void dfs1(int v){
	vis[v]=1;
	for(int i=0;i<G[v].size();i++){
		int pos=G[v][i].pos;
		if(!vis[pos]) dfs1(pos);
	}
	st.push(v);
}

void dfs2(int v){
	vis[v] = 1;
	for(int i=0;i<fG[v].size();i++){
		int pos=fG[v][i].pos;
		if(!vis[pos]) dfs2(pos);
	}
}

int kosaraju(){
	int ans=0;
	while(!st.empty()) st.pop();
	
	memset(vis,0,sizeof(vis));
	
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs1(i);
	}
	
	memset(vis,0,sizeof(vis));
	while(!st.empty()){
		int v= st.top();
		st.pop();
		if(!vis[v]){
			ans++;
			dfs2(v);
		}
	}
	return ans;
}
 
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>m){
		for(int i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			G[a].push_back(Node(b));
			fG[b].push_back(Node(a));
		}
		
		cout<<kosaraju()<<endl;
			
	}
}


