/*
（双key dijkstra + 堆优化）

Hdu3790

*/ 


#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int inf=0x7FFFFFFF;
int n,m,start,End;
int vis[1005];
int dist[1005];
int cost[1005];//注意 
struct Node{
	int pos,len;
	Node(int pos,int len) : pos(pos),len(len){}
	friend bool operator <(Node a,Node b){
		return a.len>b.len;
	}
};
struct G{
	int pos,len,sp;
	G(int pos,int len,int sp ): pos(pos),len(len),sp(sp){}
};
vector<G> Map[1005];
void init(){
	for(int i=0;i<1005;i++){
		vis[i]=0;
		Map[i].clear();
		dist[i]=inf;
		cost[i]=inf;
	}
}
void BFS(){
	priority_queue<Node> q;
	q.push(Node(start,0));
	dist[start]=0;
	cost[start]=0;
	while(!q.empty()){
		Node cur=q.top();
		q.pop();
		int pp=cur.pos;
		if(vis[pp]==1) continue;
		vis[pp]=1;
		for(int i=0;i<Map[pp].size();i++){
			int pos=Map[pp][i].pos;
			int len=Map[pp][i].len+dist[pp];
			int sp=Map[pp][i].sp+cost[pp];
			if(vis[pos]==1) continue;
			if(len<dist[pos]){//注意 
				dist[pos]=len;
				q.push(Node(pos,len));
				cost[pos]=sp;
			}else if(len==dist[pos]){//注意 
				cost[pos]=min(cost[pos],sp);
			}
		}
	}
}
int main()
{
	cin>>n>>m;
		init();
		while(m--){
			int a,b,d,p;
//			scanf("%d%d%d%d",&a,&b,&d,&p);
			cin>>a>>b>>d;
			Map[a].push_back(G(b,d,0));
		}
		scanf("%d%d",&start,&End);
		BFS();
		
		if(dist[End] ==inf ) cout<<"-1"<<endl;
		else cout<<dist[End]<<endl;
	
}
