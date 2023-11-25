/*洛谷 p1135 
电梯问题：
每个楼层有一个Ki（0<= Ki <= N）,电梯里有两个
按钮：上和下。......... 

input: //第一行 分别为 共几层楼,start，end。
	   //第二行 对应楼层的数字。 
5 1 5
3 3 1 2 5

output：最少需要几步。 
*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int N,A,B,k[500]; 
int vis[500];
struct Node{
	int pos,cnt;
	Node(int pos,int cnt) : pos(pos),cnt(cnt){}
};
int BFS(){
	memset(vis,0,sizeof(vis));
	queue<Node> q;
	q.push(Node(A,0));
	while(!q.empty()){
		Node cur=q.front();
		q.pop();
		if(cur.pos==B) return cur.cnt;
		if(vis[cur.pos]==1) continue;
		vis[cur.pos]=1;
		int pp=cur.pos+k[cur.pos];
		if(pp<=N&&!vis[pp]){
			q.push(Node(pp,cur.cnt+1));
		}
		int p=cur.pos-k[cur.pos];
		if(p>=1&&!vis[p]){
			q.push(Node(p,cur.cnt+1));
		}
	}
	return -1;
}
int main()
{
	while(cin>>N>>A>>B){
		for(int i=1;i<=N;i++) cin>>k[i];
		int ans=BFS();
		if(ans==-1) {
			cout<<"-1"<<endl;
		}else{
			cout<<ans<<endl;
		}
	}
}
