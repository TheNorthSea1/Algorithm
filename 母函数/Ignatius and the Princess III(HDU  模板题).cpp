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
int c1[200],c2[200]; 
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(int i=0;i<=n;i++) c1[i]=1;
		for(int i=2;i<=n;i++){
			for(int j=0;j<=n;j++){
				for(int k=0;j+k<=n;k+=i){
					c2[j+k]+=c1[j];
				}
			}
			for(int t=0;t<=n;t++){
				c1[t]=c2[t];
				c2[t]=0;
			}
		}
		cout<<c1[n]<<endl;
	}
}











