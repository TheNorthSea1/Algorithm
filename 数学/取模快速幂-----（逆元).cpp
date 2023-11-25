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
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn = 1e5 + 5;
const ll mod = 1e9+7;
ll quickpow(ll x,ll y,ll MOD){
	ll ans=1;
	while(y){
		if(y&1) ans=(x*ans)%MOD;
		y>>=1;
		x=(x*x)%MOD;
	}
	return ans;
}

ll get_inv(ll x){  //��x����Ԫ   ��1/x�ĸ��� 
	return quickpow(x,mod-2,mod);
}

int n,l,r,m;

ll a[maxn];
ll premul[maxn];// ǰ׺�� 
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin>>n>>m;
	Fi(1,n+1) cin>>a[i];
	
	premul[0]=1;
	
	Fi(1,n+1){
		premul[i] = premul[i-1] * a[i] % mod;
	}

	while(m--){
		cin>>l>>r;
		cout<<premul[r] * get_inv(premul[l-1]) % mod<<endl;  //ע��˴������� premul[r]/premul[l-1]%mod,����Ҫ���������е���
	}





}

