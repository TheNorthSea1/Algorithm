//https://ac.nowcoder.com/acm/problem/224933    

#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<cstdio>
#define test(a) cout << "-----" << a << "-----" << '\n'
#define ms(__x__,__val__) memset(__x__, __val__, sizeof(__x__))
#define Fi(__x__,__y__) for(int i=__x__;i<__y__;i++)
#define Fj(__x__,__y__) for(int j=__x__;j<__y__;j++)
#define eps 1e-6
#define inf 0x3f3f3f3f
#define N 50000600
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn = 5e7 + 5;

template<class T>inline void read(T &res){
	char c;T flag=1;
	while( (c=getchar())<'0'||c>'9' ) if(c=='-')flag=-1;res=c-'0';
	while( (c=getchar())>='0'&&c<='9' ) res=res*10+c-'0';res*=flag;
}
int vis[N];
int prime[N];
	
int mark[100010000];

void init(){
	int index=0;
	int nn=1e8+5;
	for(int i=2;i<N;i++){  //线性筛 --找出素数 
		if(vis[i]==0){
			prime[index++]=i;
		}
		for(int j=0;j<index&&prime[j]*i*1LL<N;j++){
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	
	
	for(int i=0;prime[i]*prime[i]<nn;i++){ //记入漂亮数 
		for(int j=i;prime[i]*prime[j]<nn;j++){
			mark[prime[i]*prime[j]]=1;
		}
	}
	for(int i=1;i<=nn;i++) mark[i]+=mark[i-1];//做一个前缀和 
}
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 	init(); 
	int t;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		cout<<mark[r]-mark[l-1]<<endl;
	}




}

