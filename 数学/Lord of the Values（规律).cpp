/*

https://codeforces.com/contest/1523/problem/B
任意 两个数 都可以通过
2 1 2 1 2 1 

这6步操作 完成 
 

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
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
		} 
		cout<<n*3<<endl;
		for(int i=1;i<=n;i+=2){
			cout<<"2 "<<i<<" "<<i+1<<endl;
			cout<<"1 "<<i<<" "<<i+1<<endl;
			cout<<"2 "<<i<<" "<<i+1<<endl;
			cout<<"1 "<<i<<" "<<i+1<<endl;
			cout<<"2 "<<i<<" "<<i+1<<endl;
			cout<<"1 "<<i<<" "<<i+1<<endl; 
		}
		
	}
}
