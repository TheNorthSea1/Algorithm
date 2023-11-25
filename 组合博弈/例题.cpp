/*
input:
2 2 5
3
2 5 12
3 2 4 7
4 2 3 7 12
5 1 2 3 4 5
3
2 5 12
3 2 4 7
4 2 3 7 12
0
output:
LWW
WWL
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int f[1001],ans[1001],n;
int sg(int t){
	bool g[1001];
	memset(g,false,sizeof(g));
	int p=t;
	for(int i=0;i<n;i++){
		int h=p-ans[i];
		if(h<0) break;
		if(f[h]==-1) f[h]=sg(h);
		g[f[h]]=true;
	}
	for(int i=0;;i++){
		if(g[f[i]]==false) 
		return i;
	}
}
int main()
{
	while(cin>>n,n){
		for(int i=0;i<n;i++){
			cin>>ans[i];
		}
		sort(ans,ans+n);
		int m;
		cin>>m;
		while(m--){
			int w;
			cin>>w;
			int s=0;
			memset(f,-1,sizeof(f));
			f[0]=0;
			while(w--){
				int t;
				cin>>t;
				if(f[t]==-1) f[t]=sg(t);
				s^=f[t];
			}
			if(s==0) cout<<"L"<<endl;
			else cout<<"W"<<endl;
		}
	}
	
}







