/*
https://ac.nowcoder.com/acm/problem/114009
1. тксц   map


2. string s;
sort( s.begin() ,s.end() ); 



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
map<string,int> mp;
string change(string s){
	string ans="";
	for(int i=0;i<s.size();i++){
		if(s[i]>='A'&&s[i]<='Z') s[i]=char((int)s[i]+32);
		ans+=s[i];
	}
	sort(ans.begin(),ans.end());
	return ans;
}
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	vector<string> vt;
	while(1){
		string s;
		cin>>s;
		if(s=="#") break;
		vt.push_back(s);
		mp[change(s)]++;
	} 
	vector<string> vv;
	for(int i=0;i<vt.size();i++){
		if(mp[change(vt[i])]==1){
			vv.push_back(vt[i]);
		}
	}
	sort(vv.begin(),vv.end());
	for(int i=0;i<vv.size();i++){
		cout<<vv[i]<<endl;
	}
}

