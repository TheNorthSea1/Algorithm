

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
#define ms(__x__,__val__) memset(__x__, __val__, sizeof(__x__))
#define FI(__x__,__y__) for(int i=__x__;i<__y__;i++)
#define FJ(__x__,__y__) for(int j=__x__;j<__y__;j++)
#define shu(__x__) int __x__;cin>>__x__
#define eps 1e-6
#define inf 0x7FFFFFFF
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn = 2e5 + 5;
const int mod = 1e9+7;
inline int gcd(int a,int b){
	return b ? gcd(b , a%b) :a;
}
int N,M;
struct Node{
	int fa;
	int val;
}bin[maxn];

int find(int x){
	int y;
	if(x!=bin[x].fa){
		y=bin[x].fa;
		bin[x].fa = find(y); // 原来的bin[x].val 是 x -> y的值 要变为 x -> R
		bin[x].val += bin[y].val;// 因为前面find(y),所以 bin[y].val 就更新为 y -> R 的值
	}											// 那么 x -> R = x->y + y->R;
	return bin[x].fa;
} 

void merge(int x,int y,int val){
	int Rx=find(x);
	int Ry=find(y);
	bin[Rx].fa=Ry;
	
	bin[Rx].val = bin[y].val + val -bin[x].val;
	 
}


int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

	while(cin>>N>>M){
	int ans=0;
	for(int i=0;i<maxn;i++) bin[i].fa=i,bin[i].val=0;
	while(M--){
		int a,b,val;
		cin>>a>>b>>val;
		
		a--;      //  题目给的是闭区间，闭区间是无法加减的
				/*
					比如 [ a , b] + [ b, c ] 不等于 [ a , c ] 
				
						(a , b] +(b , c] == (a,c]
				
				*/ 
//		if(a==b&&val!=0){   
//			ans++;
//			continue;
//		}
		
		if(find(a)==find(b)){
			
			int w= bin[a].val - bin[b].val;
			if(w!=val) ans++;
			
		}else{
			merge(a,b,val);
		}
	}
	cout<<ans<<endl;
	}
	

}

