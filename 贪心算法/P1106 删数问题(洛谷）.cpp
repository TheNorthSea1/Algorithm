//https://www.luogu.com.cn/problem/P1106#submit



#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<cstdio>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(false);
	string s;
	cin>>s;
	int k;
	cin>>k;
	int flag=0;
	while(k!=0){
		int flag=0;
		for(int i=0;i<s.size()-1;i++){
			if(s[i]-'0'>s[i+1]-'0'){
				s=s.substr(0,i)+s.substr(i+1);
				k--;
				flag=1;
				break;
			}
		}
		if(flag==0){
			s=s.substr(0,s.size()-1);
			k--;
		}
	}
	int tt=0;
	
	for(int i=0;i<s.size();i++){
		if(s[i]!='0'){
			tt=1;
		}
		if(tt==0&&s[i]=='0') continue;
		cout<<s[i];
	}
	if(tt==0) cout<<0;
	cout<<endl;
}

