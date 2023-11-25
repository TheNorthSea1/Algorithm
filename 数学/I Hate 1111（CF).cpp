// https://codeforces.com/contest/1526/problem/B
/*

所有11...1111 都可以通过  (1) X = 11*a +111*b;
又因 X = 111 = 11*10 +1；

所以 (2) X = 11*( a + 10 * b) + b;

由 (2)  可知我们可以 X%11 得到 b;

然后 由(1)   ans = (X - b*111) % 11;

if ans==0 说明 YES;

不然就是NO了 
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
using namespace std;
typedef long long ll;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int x=n%11;
		n-=x*111;
		if(n<0) {
			cout<<"NO"<<endl;
			continue;
		}
		if(n%11==0){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		
	} 
}

