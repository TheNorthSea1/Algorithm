//https://ac.nowcoder.com/acm/problem/15163

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
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn=1e5+5;
int n;
int c[maxn];//Ê÷×´Êý×é

void update(int i,int cnt){
	while(i<=maxn){
		c[i]+=cnt;
		i+=(i&-i); 
	}
} 

int sum(int i){
	int ans=0;
	while(i>0){
		ans+=c[i];
		i-=(i&-i);
	} 
	return ans;
}
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin>>n;
	ll ans=0;
	for(int i=0;i<n;i++){
		int w;
		cin>>w;
		ans+=sum(maxn)-sum(w);
		update(w,1);
	}
	cout<<ans<<endl;
}

