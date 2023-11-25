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
string a,b;
int Next[1000];
void getNext(string b){
	Next[1]=0;
	int j=0;
	for(int i=1;i<b.size()-1;i++){
		while(j>0&&b[i+1]!=b[j+1]) j=Next[j];
		if(b[i+1]==b[j+1]) j++;
		Next[i+1]=j;
	}
}
int Kmp(string a,string b){
	a="0"+a,b="0"+b;
	
//	Next_pre(b);
	getNext(b); 
	
	int cnt=0,j=0;
	for(int i=0;i<a.size()-1;i++){
		while(j>0&&a[i+1]!=b[j+1])
		 j=Next[j];
		if(a[i+1]==b[j+1]) j++;
		if(j==b.size()-1){
			cnt++;
//			cout<<i-j+2<<endl;//Êä³öÎ»ÖÃ 
			j=0;
		}
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	string zhu,cha;
	while(cin>>zhu){
		cin>>cha;
		string w=zhu+cha;
		int r=Kmp(w,w);
		int len=Next[w.size()];
		if(len==0){
			cout<<0<<endl;
		} else{
			cout<<w.substr(0,len);
			cout<<" "<<len<<endl;
		}
	}
}

