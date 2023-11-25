/*
这题真的吐了呀 
1.就是BFS结尾地方，不要 忘记return；
2. vis的访问数组特别重要。 

*/




#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int N,M,T;
char Map[2][13][13];
int vis[2][13][13];
int dir[4][2]={0,-1,0,1,1,0,-1,0};
int TIME;
struct P{
	int x,y,index;
	int time;
	friend bool operator< (P a,P b){
		return a.time>b.time;
	}
};
bool OK(int index,int x,int y){
	if(x<0||y<0||x>=N||y>=M||Map[index][x][y]=='*') return false;
	return true;
}
string BFS(){
	memset(vis,0,sizeof(vis));
	P cur,next;
	cur.x=0;
	cur.y=0;
	cur.index=0;
	cur.time=0;
	vis[0][0][0]=1;
	priority_queue<P> q;

	q.push(cur);
	while(!q.empty()){
		cur=q.top();
		q.pop();
		if(cur.time>T) return "NO";
		if(Map[cur.index][cur.x][cur.y]=='P') {
			TIME=cur.time;
		return "YES";
	}
		next.time=cur.time+1;
		for(int i=0;i<4;i++){
			 next.x=cur.x+dir[i][0];
			 next.y=cur.y+dir[i][1];
			 next.index=cur.index;
			 if(vis[next.index][next.x][next.y]==1) continue;
			 if(!OK(next.index,next.x,next.y))	continue;
			 if(Map[next.index][next.x][next.y]=='#'){
			 	if(vis[!next.index][next.x][next.y]==1) continue;
			 	if(!OK(!next.index,next.x,next.y)) continue;
			 	if(Map[!next.index][next.x][next.y]=='#') continue;
			 	next.index=!next.index;
//			 	q.push(next);
//			 	vis[next.index][next.x][next.y]==1;
//			 	continue;
			 }
			 q.push(next);	
			 vis[next.index][next.x][next.y]=1;
		}
	}
	return "NO";//注意点 
}
int main()
{
	int c;
	cin>>c;
	while(c--){
		cin>>N>>M>>T;
		int wall=0;
		for(int i=0;i<2;i++)
			for(int x=0;x<N;x++)
				for(int y=0;y<M;y++){
					cin>>Map[i][x][y];
					if(Map[i][x][y]=='*') wall++;
				}	
		cout<<BFS()<<endl;
//		cout<<TIME<<endl;
	}
}
