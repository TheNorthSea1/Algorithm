#include<bits/stdc++.h>
#define ms(__x__,__val__) memset(__x__, __val__, sizeof(__x__))
#define FI(__x__,__y__) for(int i=__x__;i<__y__;i++)
#define FJ(__x__,__y__) for(int j=__x__;j<__y__;j++)
using namespace std;
int n,m,t,Dx,Dy;
char G[30][30];
int vis[ 1<<10 ][30][30];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
struct Node{
	int stu,x,y,cnt;             // stu 看成 0 1 串  ( 1 代表 拥有这把钥匙， 0 代表 没有这把钥匙 ) 
	Node(){}
	Node(int stu , int x , int y ,int cnt):stu(stu), x(x) ,y(y) ,cnt(cnt){}
};
void init(){
	ms(G,0);
	ms(vis,0);
} 

bool ok(int x,int y,int stu){
	
	if(x<0||x>=n||y<0||y>=m||G[x][y]=='*') return false;
	
	if(G[x][y]>='A'&&G[x][y]<='J'){
		
		if(stu & (1<<(G[x][y]-65))) return true; //判断是否有对应的钥匙
		 
		else return false;
	}
	
	return true; 
}


int bfs(Node start){
	queue<Node> q;
	q.push(start);
	while(!q.empty()){
		Node cur = q.front();q.pop();
		if(cur.cnt>=t) return -1;    //时间大于等于 t 那就逃跑失败 -----bfs的特性 
		
		if(cur.x==Dx && cur.y==Dy) return cur.cnt;
		
		if(vis[cur.stu][cur.x][cur.y]) continue;
		
		vis[cur.stu][cur.x][cur.y] = 1;
		
		for(int i=0;i<4;i++){
			int X=cur.x+dir[i][0];
			int Y=cur.y+dir[i][1];
			
			if(!ok(X,Y,cur.stu)) continue;
			if(G[X][Y]>='a' && G[X][Y]<='j'){
				
				int next_stu = ( cur.stu | (1<<(G[X][Y]-97) ));  // 获得钥匙 
				
				if( vis[ next_stu ][X][Y]) continue; //如果该状态已经出现过，那么跳过 
				
				q.push(Node(next_stu,X,Y,cur.cnt+1));
			}else{
				q.push(Node(cur.stu,X,Y,cur.cnt+1));
			} 
			
		}
		
		 
	}
	
	return -1;
} 
 
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	while(cin>>n>>m>>t){
		init();
		Node start;
	
		FI(0,n)
			FJ(0,m){
				cin>>G[i][j];
				if(G[i][j] == '@'){
					start.stu=0;
					start.x=i;
					start.y=j;
					start.cnt=0;
				}
				if(G[i][j]=='^') Dx=i,Dy=j;
			}
		
		cout<<bfs(start)<<endl;
		
	}
}
