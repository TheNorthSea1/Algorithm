/*
此题的路径还原很重要。 

*/


#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int N,M;
char Map[105][105];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int vis[105][105];
int pre[105][105];
int index=0;
struct Node{
	int x,y,time;
	Node(int x,int y,int time) : x(x),y(y),time(time){}
	friend bool operator <(Node a,Node b){
		return a.time>b.time;
	}
};
bool OK(int x,int y){
	if(x<0||x>=N||y<0||y>=M||vis[x][y]==1||Map[x][y]=='X') return true;
	return false;
}
int BFS(){
	index=0;
	memset(vis,0,sizeof(vis));
	memset(pre,0,sizeof(pre));
	priority_queue<Node> q;
	q.push(Node(0,0,0));
	vis[0][0]=1;
	while(!q.empty()){
		Node cur=q.top();
		q.pop();
		if(cur.x==N-1&&cur.y==M-1){
			return cur.time;
		}
		for(int i=0;i<4;i++){
			int X=cur.x+dir[i][0];
			int Y=cur.y+dir[i][1];
			if(OK(X,Y)) continue;
			int t=cur.time+1;
			if(Map[X][Y]!='.'){
				int w=Map[X][Y]-'0';
				t=t+w;
			}
			q.push(Node(X,Y,t));
			vis[X][Y]=1;
			pre[X][Y]=i+1;
		}
	}
	return -1;	
}
void Print(int X,int Y){
	if(pre[X][Y]==0) return;
	int last_x=X-dir[pre[X][Y]-1][0];
	int last_y=Y-dir[pre[X][Y]-1][1];
	Print(last_x,last_y);
	printf("%ds:(%d,%d)->(%d,%d)\n",++index,last_x,last_y,X,Y);
	if(Map[X][Y]!='.'){
		int sum=Map[X][Y]-'0';
		while(sum--) printf("%ds:FIGHT AT (%d,%d)\n",++index,X,Y);
	}
}
int main()
{
	while(scanf("%d%d",&N,&M)!=EOF){
		memset(Map,0,sizeof(Map));
		for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			cin>>Map[i][j];
		}
		int ans=BFS();
		if(ans==-1){
			cout<<"God please help our poor hero."<<endl;
		}else{
			cout<<"It takes "<<ans<<" seconds to reach the target position, let me show you the way."<<endl;
			Print(N-1,M-1);
		}
		cout<<"FINISH"<<endl;
	}
}
