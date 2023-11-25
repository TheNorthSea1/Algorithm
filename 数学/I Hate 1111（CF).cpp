// https://codeforces.com/contest/1526/problem/B
/*

����11...1111 ������ͨ��  (1) X = 11*a +111*b;
���� X = 111 = 11*10 +1��

���� (2) X = 11*( a + 10 * b) + b;

�� (2)  ��֪���ǿ��� X%11 �õ� b;

Ȼ�� ��(1)   ans = (X - b*111) % 11;

if ans==0 ˵�� YES;

��Ȼ����NO�� 
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

