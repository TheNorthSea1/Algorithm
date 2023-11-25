#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int main()
{
	string s;
	cin>>s;
	map<string,string> mp;
	while(cin>>s){
		if(s=="END") break;
		string a;
		cin>>a;	
		mp[a]=s;
	}
	cin>>s;
	getchar();
	while(getline(cin,s)){
		if(s=="END") break;
		string p="";
		for(int i=0;i<s.size();i++){
			if(s[i]>='a'&&s[i]<='z'){
				p+=s[i];
			}else{
				if(p.size()!=0){
				map<string,string>::iterator t;
				t=mp.find(p);
				if(t!=mp.end()){
					cout<<t->second;
					}else{
						cout<<p;
					} 
				}
				p="";
				cout<<s[i];
			}
		}
		cout<<endl;
	}
 } 
