/*
https://www.luogu.com.cn/problem/P1019

字符串重复度的处理。 


*/ 


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
int n;
string words[50];
int chong[50][50];//chong[i][j],指j单词接在i后的最小重合度。
int chachong(int x,int y){//找出第y个单词接在第x单词后的最小重合度。 
	int py=0;
	for(int px=words[x].size()-1;px>=0;px--){
		for(int p=px;p<words[x].size();p++){
			if(words[x][p]!=words[y][py]){
				break;
			}
			py++;
		}
		if(py==words[x].size()-px){
			return py;
		}
		py=0;
	}
	return 0; 
} 
char C;
int ans=-1;
int vis[50];
void DFS(int p,int len){
	bool f=false;
	for(int i=0;i<n;i++){
		if(vis[i]==2) continue;//使用大于二次 
		if(chong[p][i]==0) continue;//没有重合 
		if(words[i].size()==chong[p][i]||chong[p][i]==words[p].size()) continue;//出现包含关系 
		f=true;
		len+=words[i].size()-chong[p][i];
		vis[i]++;
		DFS(i,len);
		vis[i]--;
		len-=words[i].size()-chong[p][i]; 
	}
	if(f==false){
		ans=max(len,ans);
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>n){
		for(int i=0;i<n;i++) cin>>words[i];
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			chong[i][j]=chachong(i,j);
		}
		cin>>C;
		for(int i=0;i<n;i++){
			memset(vis,0,sizeof(vis));
			if(words[i][0]==C){
				vis[i]++;
				DFS(i,words[i].size());
//				vis[i]=0;
			}
		}
		cout<<ans<<endl;	
	} 
}
/*
#include<bits/stdc++.h>
map<string,int> mp;
vector<string> vt;
string ans;
void dfs(string s){
	for(int i=0;i<vt.size();i++){
		if(mp[vt[i]]==2) continue;
		int p;
		int flag=0;
		for(int j=s.size()-1;j>=0;j--){//查询是否符合接龙 
			if(s[j]==vt[i][0]){
				string ww=s.substr(j);
				if(vt[i].find(ww)==0){
					p=s.size()-j;
					flag=1;
					break;	
				}	
			}
		}
		if(!flag) continue;
		
		string tmp1=s.substr(0,s.size()-p);
		tmp1=tmp1+vt[i];
		mp[vt[i]]++;
		dfs(tmp1);
		mp[vt[i]]--;
	}
	if(s.size()>ans.size()){
		ans=s;
	}
	
}
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int n;
	string s;
	cin>>n;
	
	Fi(0,n){
		cin>>s;
		vt.push_back(s);
	}
	char c;
	cin>>c;
	vector<string> tou;
	Fi(0,n){
		if(vt[i][0]==c) tou.push_back(vt[i]);
	}
	ans="";
	for(int i=0;i<tou.size();i++){
		mp.clear();
		mp[tou[i]]=1;
		dfs(tou[i]);
		
	}
//	cout<<ans<<endl;
	cout<<ans.size()<<endl;
	
	
	
	
	
	
}

*/ 

