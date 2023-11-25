/*
题目意思为  求 区间和 大于0 的个数;

利用前缀和可知： sum[ i ~ j ] = sum[j] - sum[i-1] > 0;
 
-> sum[j] > sum[i-1] 且 j > i-1;
 
变成了 求顺序对的问题 


https://ac.nowcoder.com/acm/contest/11212/F

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
#define ms(__x__,__val__) memset(__x__, __val__, sizeof(__x__))
#define Fi(__x__,__y__) for(int i=__x__;i<__y__;i++)
#define Fj(__x__,__y__) for(int j=__x__;j<__y__;j++)
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn=1e6+5;
int n;
ll a[maxn];
ll T[maxn];
ll ans;

void merge_sort(int L,int R){
	if(L==R) return;
	int m=L+R>>1;
	
	merge_sort(L,m);
	merge_sort(m+1,R);
	
	int x=L,y=m+1,t=L;
	
	while(x<=m&&y<=R){
		if(a[x]<a[y]){
			T[t++]=a[x++];
			
			ans+=(R-y+1);  //当 a[y] > a[x] 所以 y后面的数都大于 a[x]; 
		}else{
			T[t++]=a[y++];
		}
	}
	
	while(x<=m) T[t++]=a[x++];
	while(y<=R) T[t++]=a[y++];
	
	Fi(L,R+1) a[i]=T[i];
	
	
}
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin>>n;
	ans=0;
	Fi(1,n+1) {
	cin>>a[i],a[i]+=a[i-1];  //求前缀和
	
	
	//	if(a[i] > 0) ans++;如果merge_sort(1,n)  
	
	}
	merge_sort(0,n); // 注意此处要从 0 开始 
	cout<<ans<<endl;
	
	
}

