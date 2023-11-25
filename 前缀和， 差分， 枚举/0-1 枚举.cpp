/*
当要在 n个物品里选任意数时，利用 0-1 枚举思想。

将n 转化为 2进制 ；

如 当 n = 3 时， 枚举0 ~ 2^3-1;
就能得到 所有的情况了。    


*/

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
#define eps 1e-6
using namespace std;
typedef long long ll;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
int n,m,k;
int vis[20];
ll G[30][30];
int cnt,pp;
ll sumR[30],sumC[30]; 
void change(int w){//将数字转换为01 数组 
	memset(vis,0,sizeof(vis));
	cnt=0;//用于记录 选择行的个数 
	pp=0;
	while(w!=0){
		int q=w%2;
		vis[pp++]=q;
		if(q==1) cnt++;
		w>>=1;
	}
}
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	ll ans=0;
	if(k>=n) k=n;
	if(k>=m) k=m;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++){
		cin>>G[i][j];
		sumR[i]+=G[i][j];
	}
	
	int maxn=(1<<n)-1;
	for(int i=0;i<=maxn;i++){
		change(i);//经过该处，就能获得相应的 行--选择情况
//		 memset(sumR,0,sizeof(sumR));

		 if(cnt>k) continue; 
//		if(k-cnt>m|| k-cnt <0) continue;
//		test(cnt);
		 ll sum=0;
		 for(int j=0;j<n;j++){
		 	if(vis[j]) //如果为0 就是没选这行 
			 sum+=sumR[j];
		 }
		 memset(sumC,0,sizeof(sumC));
		 
		 for(int j=0;j<m;j++){
		 	for(int t=0;t<n;t++){
		 		if(!vis[t]) sumC[j]+=G[t][j];
			 }
		 }
		 sort(sumC,sumC+m,greater<ll>() );
		 for(int t=0;t<k-cnt;t++){
		 	sum+=sumC[t];
		 }
		 ans=max(ans,sum);
	} 
	
	cout<<ans<<endl;
	
	
	
}
