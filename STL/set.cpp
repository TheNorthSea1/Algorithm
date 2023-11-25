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
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	string s(4,'a');
//	cout<<s; 
	multiset<int> ss;
	ss.insert(1);
	ss.insert(2);
	cout<<ss.count(0)<<endl;   //set��� count �������ڷ������� �����ĸ����� 
	ss.insert(1);
	cout<<ss.count(1);
}

