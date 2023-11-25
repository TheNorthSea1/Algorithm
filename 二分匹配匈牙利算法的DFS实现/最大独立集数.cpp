/*
二分图的最大独立集。 
*/


#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=1005;
int g[inf][inf],N;
int linker[inf];
bool used[inf];
bool dfs(int L){
	for(int R=0;R<N;R++){
		if(g[L][R]==1&&used[R]==false){
			used[R]=true;
			if(linker[R]==-1||dfs(linker[R])){
				linker[R]=L;
				return true;
			}
		}
	
	}
		return false;
}
int hungary(){
	int cnt=0;
	memset(linker,-1,sizeof(linker));
	for(int L=0;L<N;L++){
		memset(used,false,sizeof(used));
		if(dfs(L)) cnt++;
	}
	return cnt;
}
int main()
{
	while(cin>>N){
		memset(g,0,sizeof(g));
		for(int i=0;i<N;i++){
			int id,n;
			scanf("%d: (%d)",&id,&n);
			for(int i=0;i<n;i++){
				int w;
				cin>>w;
				g[id][w]=1;
			}
		}
		cout<<N-(hungary()/2)<<endl;//将有好感的一对减去一半。	
	}
}
