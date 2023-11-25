/*
1.反向建图。
2.根据题意清除相应的点。
3。在清楚点的注意事项。 






*/ 


#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
const int inf=2e5+5;
struct Node{
	int pos,len;
	Node(int pos,int len) : pos(pos),len(len){}
	friend bool operator < (Node a,Node b){
		return a.len>b.len;
	}
};
vector<Node> g[inf];
int n,m,start,End;
int dist[inf],vis[inf];
int biaoji[inf],tm[inf];//注意tm数组的用意。 
void init(){
	for(int i=0;i<inf;i++){
		g[i].clear();
		dist[i]=inf;
		vis[i]=0;
		biaoji[i]=0;
		tm[i]=0;
	}
}
void bfs_clear(){
	biaoji[End]=1;
	queue<int> qq;
	qq.push(End);
	while(!qq.empty()){
		int cur=qq.front();
		qq.pop();
		for(int i=0;i<g[cur].size();i++){
			int pos=g[cur][i].pos;
			if(biaoji[pos]==0){
				biaoji[pos]=1;
				qq.push(pos);
			}
		}
	}
	 //注意这里最好有第二个数组标记，在一个数组里删点有后效型，如果一个点开始被标记，它通过一个序号比它小的点删除了，
       //那么访问到它的时候，就会被当成开始就没被标记的点，会通过它把合法点删除。
      //这样做完之后，合法点都被标记了。
	memcpy(tm,biaoji,sizeof(biaoji));
	for(int i=1;i<=n;i++){
		if(biaoji[i]==0){
			for(int j=0;j<g[i].size();j++){
				if(biaoji[g[i][j].pos]==1){
					tm[g[i][j].pos]=0;
				}
			}
		}
	}
}
int dijst(){
	priority_queue<Node> q;
	q.push(Node(End,0));
	dist[End]=0;
	while(q.size()){
		Node cur=q.top();
		q.pop();
		if(cur.pos==start) return dist[start];
		if(vis[cur.pos]) continue;
		vis[cur.pos]=1;
		int pp=cur.pos;
		for(int i=0;i<g[pp].size();i++){
			int pos=g[pp][i].pos;
			if(tm[pos]==0) continue;
			int len=g[pp][i].len+dist[pp];
			if(!vis[pos]&&len<dist[pos]){
				dist[pos]=len;
				q.push(Node(pos,len));
			}
		}
	}
	return -1;
}
int main()
{
	scanf("%d%d",&n,&m);
		init();
		while(m--){
			int x,y;
			scanf("%d%d",&x,&y);
			if(x!=y){
				g[y].push_back(Node(x,1));
			}
		}
		scanf("%d%d",&start,&End);
		bfs_clear();
//		for(int i=1;i<=n;i++){
//			cout<<tm[i]<<" ";
//		}
		int ans=dijst();
		if(ans==-1){
			cout<<-1<<endl;
		}else{
			cout<<ans<<endl;
		}
}
