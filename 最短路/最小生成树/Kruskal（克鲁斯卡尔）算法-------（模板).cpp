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
const int maxn=2e6+5;
struct Node{
	ll x,y,len;
	friend bool operator<(Node a,Node b){
		return a.len<b.len;
	}
}edge[maxn]; 
int n,m;
int bin[maxn];
int find(int x){
	int root=x;
	while(root!=bin[root]) root=bin[root];
	int i=x,j;
	while(i!=root){
		j=bin[i];
		bin[i]=root;
		i=j;
	}
	return root;
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n>>m){
		for(int i=0;i<=n;i++){
			bin[i]=i;
		} 
		for(int i=0;i<m;i++){
			cin>>edge[i].x>>edge[i].y>>edge[i].len;
		}
		ll sum=0;
		sort(edge,edge+m);
		for(int i=0;i<m;i++){

			int x=find(edge[i].x);
			int y=find(edge[i].y);
			if(x==y) continue;
			bin[x]=y;
			sum+=edge[i].len;
			
		}
		cout<<sum*2<<endl;
	}
}

