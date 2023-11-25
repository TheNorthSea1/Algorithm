/*
收获 就是如何产生aaa 到 zzz 的字符 

https://codeforces.com/contest/1536/problem/B



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
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,flag=0;
		cin>>n;
		string s;
		cin>>s;
		set<string> st;
		for(int i=0;i<n;i++){  //set 储存的是相应由一个到三个的字符 
			string ss;
			for(int j=i;j<i+3&&j<n;j++){
				ss.push_back(s[j]); // char 类型 加入到 sting 类型中 
				st.insert(ss);
			}
		}
		
		for(int i=1;i<=3;i++){
			string t(i,'a');//产生i长的 a 字符串
			while(true){
				if(st.find(t)==st.end()){
					cout<<t<<endl;
					flag=1;
					break;
				}	
				int index=i-1;
			
				while(index>=0 && t[index]=='z'){
					t[index]='a';
					index--;
				}
			
				if(index<0) break;
				
				t[index]++;
				
			}
			if(flag) break; 						   
		}		
	}
}

