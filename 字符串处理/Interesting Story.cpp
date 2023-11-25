//https://codeforces.com/contest/1551/problem/C 

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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n][6];//用于存放每个单词在该组单词里的出现次数；
		ms(a,0);
		Fi(0,n){
			string s;
			cin>>s;
			Fj(0,s.size()){
				a[i][(int)s[j]-97]++;
			}
			a[i][5]=s.size();//a[i][5] 存的是该单词的长度。 
		} 
		
		
		
		int ans=0;
		Fi(0,5){ //枚举每个单词
			int ww=0;
			vector<int> vt(n);
			Fj(0,n){
				vt[j]=(a[j][i]*2-a[j][5]);
			} 
			
			sort(vt.rbegin(),vt.rend());  //重大到小排序   特别注意 
			
			int cnt=0;
			for(auto u:vt){
				cnt+=u;
				if(cnt>0) ww++;
				else cnt-=u;
			}
			ans=max(ans,ww);
			
		} 
		
		cout<<ans<<"\n";
		
		
		
		
		 
	}
}
