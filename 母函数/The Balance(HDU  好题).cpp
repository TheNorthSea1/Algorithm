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
const int maxn=30000;
int c1[maxn],c2[maxn];
int w[maxn]; 
int main()
{
	ios::sync_with_stdio(false);
	int n;
	while(cin>>n){
		for(int i=0;i<n;i++) cin>>w[i];
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		c1[0]=1,c1[w[0]]=1;
		int sum=w[0];
		for(int i=1;i<n;i++){
			for(int j=0;j<=sum;j++){
				for(int k=0;k<2;k++){
					c2[j+w[i]*k]+=c1[j];
					c2[(abs(j-w[i]*k))]+=c1[j];
				}
			}
			sum+=w[i];
			for(int t=0;t<=sum;t++){
				c1[t]=c2[t];
				c2[t]=0;
			}
		}
		vector<int> vet;
		for(int i=1;i<=sum;i++){
			if(!c1[i]){
				vet.push_back(i);
			}
		}
		cout<<vet.size()<<endl;
		for(int i=0;i<vet.size();i++){
			if(i!=0) cout<<" ";
			cout<<vet[i]; 
		}
		if(vet.size()!=0) cout<<endl;
	}
}

