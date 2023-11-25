/*
牛客 模拟战役
 https://ac.nowcoder.com/acm/problem/14698

我用了两个dfs 但其是可以只用一个dfs 


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
using namespace std;
typedef long long ll;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
char G[1000][1000];
int biao[1000][1000];
int m; 
int dir[8][2]={1,1,-1,-1,1,-1,-1,1,1,0,0,1,-1,0,0,-1};
int cnt;
bool OK1(int x,int y){
	if(x<1||x>4||y<1||y>m||G[x][y]=='.'||biao[x][y]==1) return false;
	return true;	
}

bool OK2(int x,int y){
	if(x<5||x>8||y<1||y>m||G[x][y]=='.'||biao[x][y]==1) return false;
	return true;	
}

void dfs1(int x,int y){
	if(!OK1(x,y)) return;
	cnt++;
	biao[x][y]=1;
	for(int i=0;i<8;i++){
		int X=x+dir[i][1];
		int Y=y+dir[i][0];
		dfs1(X,Y);
	}
}

void dfs2(int x,int y){
	if(!OK2(x,y)) return;
	cnt++;
	biao[x][y]=1;
	for(int i=0;i<8;i++){
		int X=x+dir[i][1];
		int Y=y+dir[i][0];
		dfs2(X,Y);
	}
}

int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin>>m;
	for(int i=1;i<=8;i++)
		for(int j=1;j<=m;j++){
			cin>>G[i][j]; 
		}
			
	vector<int> qi;
	vector<int> si;
	
	for(int i=1;i<=4;i++){
		for(int j=1;j<=m;j++){
			cnt=0;
			if(OK1(i,j)){
				dfs1(i,j);
			}
			if(cnt!=0) si.push_back(cnt);
		}
	}
	
	for(int i=5;i<=8;i++){
		for(int j=1;j<=m;j++){
			cnt=0;
			if(OK2(i,j)){
				dfs2(i,j);
			}
			if(cnt!=0) qi.push_back(cnt);
		}
	}
//	test(qi.size());
//	test(si.size());
	if(qi.size()<=si.size()-1){
		cout<<"-1"<<endl;
	}else{
		sort(qi.begin(),qi.end());
		int t=si.size()-1;
		int ans=0;
		for(int i=t;i<qi.size();i++){
			ans+=qi[i];
		}
		cout<<ans<<endl;
	}
	
	
	
}

