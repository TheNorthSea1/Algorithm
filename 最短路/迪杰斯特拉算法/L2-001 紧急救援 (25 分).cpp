/*
难点：1.路径条数的记录。
 	2.两个考虑点，最短路和最大救援数量。 
	3.输出最大人数的路径。 
6 7 0 3
30 100 20 50 20 20
0 1 1
1 3 5
1 2 2
2 3 3
0 4 1
4 5 2
5 3 3
*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int N,M,S,D;
const int inf=0x7FFFFFFF;
int dist[505],vis[505],peo[505],pre[505];
int num[505];
int ways[505];//注意 
struct Node{
	int pos,len;
	Node(int pos,int len) :pos(pos),len(len) {}
	friend bool operator<(Node a,Node b){
		return a.len>b.len;
	}
};
vector<Node> Map[505];
void init(){
	for(int i=0;i<505;i++){
		Map[i].clear();
		dist[i]=inf;
		num[i]=0;
		vis[i]=0;
		peo[i]=0;
		pre[i]=-1;
		ways[i]=0;
	}
}
void BFS(){
	priority_queue<Node> q;
	q.push(Node(S,0));
	dist[S]=0;
	num[S]=peo[S];
	ways[S]=1;
	while(!q.empty()){
		Node cur=q.top();
		q.pop();
		int pp=cur.pos;
		if(cur.pos==D) return;
		if(vis[pp]==1) continue;
		vis[pp]=1;
		for(int i=0;i<Map[pp].size();i++){
			int pos=Map[pp][i].pos;
			int len=Map[pp][i].len+dist[pp];
			int renshu=peo[pos]+num[pp];
			if(vis[pos]==1) continue;
			if(len<dist[pos]){
				ways[pos]=ways[pp];//注意 
				dist[pos]=len;
				num[pos]=renshu;
				q.push(Node(pos,len));
				pre[pos]=pp;
			}else if(len==dist[pos]){
				ways[pos]+=ways[pp];//注意 
//				num[pos]=max(renshu,num[pos]);
//				pre[pos]=pp;
				if(renshu>num[pos]){//如果写成上面的情况，就会有问题。 
					num[pos]=renshu;
					pre[pos]=pp;//该处的更新应当人数大于原人数才能更新，这样才能输出最大人数的路径。 
				}
			}
		}
	}
}
int main()
{
	while(cin>>N>>M>>S>>D){
		init();
		for(int i=0;i<N;i++) cin>>peo[i];
		while(M--){
			int a,b,c;
			cin>>a>>b>>c;
			Map[a].push_back(Node(b,c));
			Map[b].push_back(Node(a,c));
		}
		BFS();
		cout<<ways[D]<<" "<<num[D]<<endl;
		vector<int> v;
		int t=D;
	 	while(1){
	 		if(pre[t]==-1){
	 			v.push_back(t);
	 			break;
			 }
			 v.push_back(t);
			 t=pre[t];
		 }
//		cout<<v.size()<<endl;
		for(int i=v.size()-1;i>=0;i--){
			if(i!=v.size()-1) cout<<" ";
			cout<<v[i];
		}
		cout<<endl;
	}
 } 
