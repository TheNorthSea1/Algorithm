/*
注意时间复杂度 

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
const int maxn=300005;
int c1[maxn],c2[maxn];
struct Node{
    int val;
    int num;
};
int main()
{
    ios::sync_with_stdio(false);
    int n;
    while(cin>>n){
		if(n<0) break;
    	Node node[n];
        memset(node,0,sizeof(node));
        
        for(int i=0;i<n;i++) cin>>node[i].val>>node[i].num;
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        int sum=0;
		for(int i=0;i<n;i++){
			sum+=node[i].val*node[i].num;
		}
        for(int i=0;i<=node[0].num;i++){
            c1[i*node[0].val]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum/2;j++){
                if(c1[j]){
                	for (int k=0;k+j<=sum/2&&k<=node[i].val*node[i].num;k+=node[i].val)
        				c2[j+k]+=c1[j];
				}
            }
            for(int t=0;t<=sum/2;t++){
                c1[t]=c2[t];
                c2[t]=0;
            }
        } 
        int ww=sum/2,p;
        for(int t=ww;t>=0;t--){
            if(c1[t]){
                p=t;
                break;
            }
        }
        cout<<sum-p<<" "<<p<<endl;
    }
    
    
    
    
    
}