#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int inf=1e5+5;
ll N,M,s;
ll dist[inf];
ll vis[inf];
struct Node{
	ll pos;
	Node(int pos) : pos(pos) {}
	friend bool operator < (Node a,Node b){
		return a.pos>b.pos;
	}
};
vector<Node> Map[inf];
int in[inf];
vector<int> ans;
void topsort(){
	priority_queue<Node> q;
	for(int i=1;i<=N;i++) if(in[i]==0) q.push(i);
	while(!q.empty()){
		Node p=q.top();
		q.pop();
		ans.push_back(p.pos);
		for(int i=0;i<Map[p.pos].size();i++){
			int pp=Map[p.pos][i].pos;
			in[pp]--;
			if(in[pp]==0) q.push(pp);
		}
	}
}
void init(){
	for(int i=0;i<=N;i++){
		Map[i].clear();
	}
	ans.clear();
}
int main()
{
	while(cin>>N>>M){
		init();
		memset(in,0,sizeof(in));
		while(M--){
			int a,b;
			cin>>a>>b;
			Map[a].push_back(Node(b));
			in[b]++;
		}
//		for(int i=1;i<=N;i++){
//			cout<<in[i]<<" ";
//		} 
		topsort();
		for(int i=0;i<ans.size();i++){
			if(i!=0) cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;
	}
}
