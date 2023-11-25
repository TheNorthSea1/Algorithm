/*https://ac.nowcoder.com/acm/problem/219046

3 8 12 15 16 16
3 15 16一组
8 12 16一组

错误做法   对这6个数 sort 然后分别-比较 1，2，3和4，5，6是否构成三角形 


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
const int maxn=1e5+5;
int t;
int a[8];
int vis[7];
bool dfs(int pos,int cnt){
	if(pos>6&&cnt<3) return 0;
	if(cnt==3){
		vector<int> v1;
		vector<int> v2;
		for(int i=1;i<=6;i++){
			if(vis[i]) v1.push_back(a[i]);
			else v2.push_back(a[i]);
		}
		sort(v1.begin(),v1.end());
		sort(v2.begin(),v2.end());
		if(v1[0]+v1[1]>v1[2]&&v2[0]+v2[1]>v2[2]) return 1;
		else return 0;
	}
	
	if(dfs(pos+1,cnt)){ //不选择 pos的值 
		return 1;
	}
	
	vis[pos]=1;
	if(dfs(pos+1,cnt+1)){//选择pos的值
		return 1;
	}
	
	vis[pos]=0;
	return 0;
	
	 
}
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		ms(vis,0); 
		for(int i=1;i<=6;i++) cin>>a[i];
		if(dfs(1,0)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	
	
}

