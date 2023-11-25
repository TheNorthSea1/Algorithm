/*
����Ľⷨ :

1. ����map<int,bool> ����������ֹ��󣬶��޷�������ά���顣
 
2.����������ͼ������һ����ͨ�����еĵ㣬����֮����ܻ����ܶ����ߣ�
��ֻ��Ҫһ���߾���ȷ������֮��Ĺ�ϵ������������ô�����߶������Ż���������bfs��ÿ�ΰ�vɾ����
Ȼ��ʣ������û���뼯���еĵ��Ƿ���v�й�ϵ���й�ϵ�����һ��������ٰ����ɾ�ˣ� 





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
				swap(g[i],g.back()); //��Ҫɾ���ĵ�ŵ���� 
				g.pop_back();
				i--;     //Ҫע����ǣ�swap��iָ����û�м���������Ҫi--�� 
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

