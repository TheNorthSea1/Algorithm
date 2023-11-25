/*
该题的解法 :

1. 利用map<int,bool> 解决由于数字过大，而无法创建二维数组。
 
2.由于是无向图，对于一个连通分量中的点，他们之间可能会连很多条边，
但只需要一条边就能确定他们之间的关系，所以其他那么多条边都可以优化掉，利用bfs，每次把v删掉，
然后看剩下所有没加入集合中的点是否与v有关系，有关系则加入一个集合里，再把这点删了， 





*/




#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<cstdio>
using namespace std;
typedef long long ll;
const int inf=2e5+5;
map<int,bool> mp[inf];
vector<int> g,ans; 
int BFS(int v){
	queue<int> q;
	q.push(v);
	int cnt=0;
	while(!q.empty()){
		int cur=q.front();
		q.pop();
		cnt++;
		for(int i=0;i<g.size();i++){
			int pp=g[i];
			if(!mp[cur][pp]){
				swap(g[i],g.back()); //把要删除的点放到最后。 
				g.pop_back();
				i--;     //要注意的是，swap后i指的数没有检查过，所以要i--。 
				q.push(pp);
			}
		}
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) g.push_back(i);
	while(m--){
		int a,b;
		cin>>a>>b;
		mp[a][b]=1;
		mp[b][a]=1;
	}
	while(!g.empty()){
		int p=g.back();
		g.pop_back();
		ans.push_back(BFS(p));
	}
	cout<<ans.size()<<endl;
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		if(i!=0) cout<<" ";
		cout<<ans[i];
	} 
}

