//https://pintia.cn/problem-sets/994805046380707840/problems/1386335159927652362
 

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
#define FI(__x__,__y__) for(int i=__x__;i<__y__;i++)
#define FJ(__x__,__y__) for(int j=__x__;j<__y__;j++)
#define SC(__x__) scanf("%d",&__x__)
#define PF(__x__) printf("%d",__x__)
#define PN(__x__) printf("%d\n",__x__)
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn = 1e5 + 5;

map<vector<int>,int> mp;// vecter也可以作为键值 

struct Node{
	int cnt;
	vector<int> v;
	Node(vector<int> v,int cnt) : v(v),cnt(cnt){}
	friend bool operator<(Node a,Node b){
		if(a.cnt!=b.cnt){
			return a.cnt>b.cnt;
		}else{
			return a.v<b.v;    //vector 之间可以比较大小 
		}
	}
}; 
vector<Node> ans;

int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	FI(0,n){
		vector<int> tt;
		
		FJ(0,m){
			int x;
			cin>>x;
			tt.push_back(x);	
		}
		
		if(!mp[tt]){
			mp[tt]=1;
		}else{
			mp[tt]++;
		}
	}
	for(auto u:mp){
		ans.push_back(Node(u.first,u.second));
	}
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(auto u:ans){
		cout<<u.cnt;
		for(auto t:u.v){
			cout<<" "<<t;
		}
		cout<<endl;
	}




}

