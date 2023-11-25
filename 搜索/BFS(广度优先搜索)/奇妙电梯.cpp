/*��� p1135 
�������⣺
ÿ��¥����һ��Ki��0<= Ki <= N��,������������
��ť���Ϻ��¡�......... 

input: //��һ�� �ֱ�Ϊ ������¥,start��end��
	   //�ڶ��� ��Ӧ¥������֡� 
5 1 5
3 3 1 2 5

output��������Ҫ������ 
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
