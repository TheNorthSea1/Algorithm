//https://ac.nowcoder.com/acm/problem/14326


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
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int n;
	while(cin>>n,n){
		int a[n+1];
		while(1){
			cin>>a[1];
			if(!a[1]) break;
			Fi(2,n+1) cin>>a[i];
			stack<int> st;
			int p=1;
			for(int i=1;i<=n;i++){
				if(st.empty()){
					st.push(i);
					if(i==a[p]){
						st.pop();
						p++;
					}
				}else if(st.top()==a[p]){
					while(!st.empty()&&st.top()==a[p]){  //此处需要注意 
						st.pop();
						p++;
					}
					st.push(i);
				}else{
					st.push(i);
				}
			}
			while(!st.empty()&&st.top()==a[p]){
				st.pop();
				p++;
			}
			if(!st.size()){
				cout<<"Yes"<<"\n";
			}else{
				cout<<"No"<<"\n";
			}
		}
		cout<<"\n";
	}






}

