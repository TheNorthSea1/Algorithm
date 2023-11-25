/*
https://www.luogu.com.cn/problem/P1119
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=1e9;//ע��˴������ֵ 
int N,M;
int huifu[500];
int dist[500][500];
void Floyd(int k){
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++){
		if(dist[i][j]>dist[i][k]+dist[k][j]){
			dist[i][j]=dist[i][k]+dist[k][j];
			dist[j][i]=dist[i][k]+dist[k][j];
		}
	}
	return;
}
void init(){
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++){
		dist[i][j]=inf;
		if(i==j) dist[i][j]=0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>N>>M){
		init();
		for(int i=0;i<N;i++) cin>>huifu[i];
		while(M--){
			int a,b,c;
			cin>>a>>b>>c;
			dist[a][b]=c;
			dist[b][a]=c;
		} 
		int Q;
		cin>>Q;
		int now=0;
		for(int i=0;i<Q;i++){
			int start,End,time;
			cin>>start>>End>>time;
			while(huifu[now]<=time&&now<N){
				Floyd(now);
				now++; 
			}
			if(huifu[start]>time||huifu[End]>time){
				cout<<-1<<endl;
				continue;
			}
			if(dist[start][End]!=inf){
				cout<<dist[start][End]<<endl;
			}else{
				cout<<-1<<endl;
			}
		}
	}	
	
}

