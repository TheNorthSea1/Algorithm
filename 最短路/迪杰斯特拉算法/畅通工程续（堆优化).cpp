/*
对dijkstra的堆优化实现法 




*/
#include<iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include<cmath>
#define maxn 200 + 10
#define INF 0x3f3f3f3f
using namespace std;
const int mod=1e5;
struct node {
	int v, len;
	node(int v = 0, int len = 0) :v(v), len(len) {}
	bool operator < (const node &a)const { //距离从小到大排序
		return len > a.len;
	}
};
vector<node>G[maxn];
bool vis[maxn];
int dis[maxn];
void init() {//注意初始化。 
	for (int i = 0; i<maxn; i++) {
		G[i].clear();
		vis[i] = false;
		dis[i] = INF;
	}
}
int dijkstra_heap() {
	priority_queue<node>Q;
	Q.push(node(0, 0));//加入队列并排序
	dis[0] = 0;
	while (!Q.empty()) {
		node now = Q.top(); //取出当前最小的
		Q.pop();
		int v = now.v;
		if(vis[now.v]) continue;
		vis[now.v]=1 //如果标记过了 直接continue。。。。这里也要重点注意 
	
		for (int i = 0; i<G[v].size(); i++) { //更新
			int v2 = G[v][i].v;
			int len = G[v][i].len+dis[v];//这里要重点注意 
			if (!vis[v2] &&  len<dis[v2]) {
				dis[v2] =  len;
				Q.push(node(v2, dis[v2]));
			}
		}
	}
//	return dis[m];
}
int n, m;
int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		init();
		for (int i = 0; i<m; i++) {
			int a, b;
			int len=pow(2,i);
			len=len%mod;
			cin>>a>>b;
			G[a].push_back(node(b, len));
			G[b].push_back(node(a, len));
		}
//		int s, t;
//		scanf("%d%d", &s, &t);
//		int ans = dijkstra_heap(s, t);
//		if (ans == INF)
//			printf("-1\n");
//		else
//			printf("%d\n", ans);
		for(int i=1;i<n;i++){
			if(dis[i]!=INF){
				cout<<dis[i]<<endl;
			}else{
				cout<<-1<<endl;
			}
		}
	}
	return 0;

}