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
	int n;
	while(cin>>n){
		int a[n+2];
		int b[n+2];//b[i] 表示 i~n中的最大值
		ms(a,0);
		ms(b,0);
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=n;i>0;i--) b[i]=max(b[i+1],a[i]);//求B数组
		
		stack<int> st;
		vector<int> v;
		
		for(int i=1;i<=n;i++){
			if(st.size()==0) st.push(a[i]);
			else{
				if(st.top() < b[i]){
					st.push(a[i]);
				}else{
					int tt=st.top();
					v.push_back(tt);
					st.pop();
					i--; //注意此处，i暂停在该点 
				}
			}
		}
		while(!st.empty()){
			int tt=st.top(); 
			v.push_back(tt);
			st.pop();
		} 
		for(int i=0;i<v.size();i++){
			if(i!=0) cout<<" ";
			
			cout<<v[i];
		}
	}
}


/*

5
5 1 3 4 2   

*/

