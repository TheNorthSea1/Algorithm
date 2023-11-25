//https://codeforces.com/gym/103055/problem/J 
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
int n,m,T;

struct Node{
	int pos;
	int len;
	Node(int pos,int len): pos(pos),len(len){}
	
	friend bool operator<(Node a,Node b){
		return a.len>b.len;
	}
};
vector<Node> G[3005];
int dist[3005];
int dp[5000];
int vis[5000];
void dijst(){
	priority_queue<Node> q;
	dist[1]=0;
	q.push(Node(1,0));
	while(!q.empty()){
		Node cur = q.top();
		q.pop();
		
		int pos=cur.pos;
		if(vis[pos]) continue;
		vis[pos]=1;
		for(int i=0;i<G[pos].size();i++){
			int Pos=G[pos][i].pos;
			int len=G[pos][i].len+dist[pos];
			if(!vis[Pos]&&len<dist[Pos]){
				dist[Pos]=len;
				q.push(Node(Pos,len));
			}
		}
	}
}
int val[3005];
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 	
	cin>>n>>m>>T;
	
	for(int i=0;i<n+1;i++) dist[i]=inf;
	
	Fi(2,n+1) cin>>val[i];
	Fi(0,m){
		int a,b;
		cin>>a>>b;
		if(a==b) continue;
		G[a].push_back(Node(b,1));
		G[b].push_back(Node(a,1));
	}
	dijst();

	for(int i=2;i<=n;i++){
		for(int j=dist[i]*2;j<=T;j++){
			dp[j] = max(dp[j] ,dp[j - dist[i]*2]+val[i]);
		}
	}

	for(int i=1;i<=T;i++){
		if(i!=1) cout<<" ";
		cout<<dp[i];
	}
	cout<<endl;

}

