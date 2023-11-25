#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int inf=50505050;
int n,m;
int price[1005];
int vis[1005][105];
int dist[1005][105];
int start,End,cap;

struct graph{
	int pos,len;
	graph(int pos,int len) : pos(pos),len(len){}
};
vector<graph> G[1005];
struct Node{
	int pos,price,cup;
	Node(int pos,int price,int cup) : pos(pos),price(price),cup(cup){}
	
	friend bool operator <(Node a,Node b){
		return a.price>b.price;
	}

};
void init(){
	for(int i=0;i<1005;i++){
		price[i]=0;
		G[i].clear();
		for(int j=0;j<105;j++){
			vis[i][j]=0;
			dist[i][j]=inf;
		}
	}
}
void iniit(){
	memset(vis,0,sizeof(vis));
	for(int i=0;i<1005;i++)
	for(int j=0;j<105;j++){
		dist[i][j]=inf;
	}
}
int BFS(){
	iniit();
	priority_queue<Node> q;
	q.push(Node(start,0,0));
	dist[start][0]=0;
	while(!q.empty()){
		Node cur=q.top();
		q.pop();
		if(cur.pos==End) return cur.price;
		if(vis[cur.pos][cur.cup]==1) continue;
		vis[cur.pos][cur.cup]=1;
		if(cur.cup+1<=cap&&vis[cur.pos][cur.cup+1]==0){
			
			int pp=cur.price+price[cur.pos];
			int cc=cur.cup+1;
			dist[cur.pos][cc]=pp;//зЂвт 
			q.push(Node(cur.pos,pp,cc));
		}
		int Pos=cur.pos;
		for(int i=0;i<G[Pos].size();i++){
			int weizhi=G[Pos][i].pos;
			int Cup=cur.cup-G[Pos][i].len;
			if(Cup<0) continue;
			if(vis[weizhi][Cup]==0&&cur.price<dist[weizhi][Cup]){
				dist[weizhi][Cup]=cur.price;
				q.push(Node(weizhi,cur.price,Cup));//зЂвт 
			}
		}
	}
	return -1;
}
int main()
{
	cin>>n>>m;
	init();
	for(int i=0;i<n;i++){
		cin>>price[i];
	}
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		G[a].push_back(graph(b,c));
		G[b].push_back(graph(a,c));
	}
	int t;
	cin>>t;
	while(t--){
		cin>>cap>>start>>End;
		int ans=BFS();
		if(ans==-1) cout<<"impossible"<<endl;
		else cout<<ans<<endl;
	}
}
