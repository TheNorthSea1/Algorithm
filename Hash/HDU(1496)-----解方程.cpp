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
const int MAX=50020;
int a,b,c,d;
int f[MAX],g[MAX],pin[101];
int Hash(int k){
	int t=k%MAX;
	if(t<0) t+=MAX;
	while(f[t]!=0&&g[t]!=k) t=(t+1)%MAX;
	return t;
} 
int main()
{
	ios::sync_with_stdio(false);
	int s,p;
	for(int i=1;i<101;i++) pin[i]=i*i; 
	while(cin>>a>>b>>c>>d){
		if(a>0&&b>0&&c>0&&d>0||a<0&&b<0&&c<0&&d<0){
			cout<<"0"<<endl;
			continue;
		}
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		int sum=0;
		for(int i=1;i<101;i++)
		for(int j=1;j<101;j++){
			s=a*pin[i]+b*pin[j];
			p=Hash(s);
			g[p]=s,f[p]++;
		}
		for(int i=1;i<101;i++)
		for(int j=1;j<101;j++){
			s=-(c*pin[i]+d*pin[j]);
			p=Hash(s);
			sum+=f[p];
		}
		cout<<sum*16<<endl;
	}
}

