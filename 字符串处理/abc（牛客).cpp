/*
https://ac.nowcoder.com/acm/problem/25125



做一个前缀和一个后缀和，前缀和sum1[i]记录位置1...i中a的个数，
后缀和sum2[i]记录i...n中c的个数。从前往后枚举字符串的所有位置，
如果当前位置i的字符为'b'，答案加上sum1[i-1]*sum2[i+1]即可，时间复杂度O(n)。

*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const int inf=1e5+5;
int main()
{
	string s;
	cin>>s;
	int a[inf],c[inf];
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	int cnt=0;
	for(int i=0;i<s.length();i++){//对A进行前缀和 
		if(s[i]=='a'){
			cnt++;
		}
		a[i]=cnt;
	}
	cnt=0;
	for(int i=s.length()-1;i>=0;i--){//对C进行后缀和 
		if(s[i]=='c'){
			cnt++;
		}
		c[i]=cnt;
	}
	ll ans=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='b'){
			ans+=a[i-1]*c[i+1]; 
		}
	}
	cout<<ans<<endl;
}

