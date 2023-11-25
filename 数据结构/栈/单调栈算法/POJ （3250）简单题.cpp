/*
POJ 3250 

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
const int maxn=1e5+5;
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int n;
	cin>>n;
	ll ans=0;		
	stack<ll> st;
	Fi(0,n){
		ll x;
		cin>>x;
		while(!st.empty()&&x>=st.top()) st.pop();  
		ans+=st.size();    //问题转化为 第i头牛 前面有几头牛能看到他 
		st.push(x);	
	} 
	cout<<ans<<endl;
}

