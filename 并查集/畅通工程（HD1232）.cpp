#include<iostream>
using namespace std;
int ans[1024];
int find(int root){
	int a=root;
	while(ans[a]!=a){
		a=ans[a];
	}
	return a;
}
void merge(int a,int b){
	int x,y;
	x=find(a);
	y=find(b);
//	if(x!=y)
		ans[x]=y;
}
int main()
{
	int N,M;
	while(scanf("%d",&N),N){
		scanf("%d",&M);
		for(int i=1;i<=N;i++){
			ans[i]=i;
		}
		while(M--){
			int a,b;
			scanf("%d%d",&a,&b);
			merge(a,b);
		}
		int cnt=0;
		for(int i=1;i<=N;i++){
			if(ans[i]==i){
				cnt++;
			}
		}
		cout<<cnt-1<<endl;
	}
}
