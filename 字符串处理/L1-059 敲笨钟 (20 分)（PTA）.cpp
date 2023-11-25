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
#define Fi(__x__,__y__) for(int i=__x__;i<__y__;i++)
#define Fj(__x__,__y__) for(int j=__x__;j<__y__;j++)
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn = 1e5 + 5;
int main()
{
// 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	getchar();
	while(t--){
		string s;
		getline(cin,s);
		int pos=s.find(',');
		int p=s.find('.');
		if(s[pos-1]!='g'||s[pos-2]!='n'||s[pos-3]!='o'||s[p-1]!='g'||s[p-2]!='n'||s[p-3]!='o'){
			cout<<"Skipped"<<endl;
			continue;
		}
		vector<string> vt;
		string tmp="";
		Fi(0,s.size()){
			if(s[i]!=' '){
				tmp=tmp+s[i];
			}else{
				vt.push_back(tmp);
				tmp="";
			}
		}
		vt.push_back(tmp);
		
		vt[vt.size()-1]="zhong.";
		vt[vt.size()-2]="ben";
		vt[vt.size()-3]="qiao";
		Fi(0,vt.size()){
			if(i!=0) cout<<" ";
			cout<<vt[i]; 
		}
		cout<<endl;
		
		
	}		
	
						
		
						
					
					
			
}

