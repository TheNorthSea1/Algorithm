/*
https://ac.nowcoder.com/acm/contest/11211/A
就是考察最长上升子序列---------------nlog(n) 的复杂度
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
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int n;
	string s;
	cin>>n>>s;
	int arr[n+1],len=1;
	memset(arr,0,sizeof(arr));
	arr[1] = s[0]-'A';
	for(int i=1;i<n;i++){
		int x=s[i]-'A';
		if(x>=arr[len]){
			arr[++len]=x;
		}else{
			int pos=upper_bound(arr+1,arr+1+len,x)-arr;
			arr[pos]=x;
		}
	}
	cout<<n-len<<endl;
}
