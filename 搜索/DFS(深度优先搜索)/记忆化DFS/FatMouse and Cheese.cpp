#include<bits/stdc++.h>
using namespace std;
int n,k;
int Map[105][105];
int dp[105][105];
int dir[4][2]={0,1,1,0,-1,0,0,-1};
bool OK(int x,int y);
int dfs(int x,int y){
	int anwser=0;
	if(dp[x][y]!=0) return dp[x][y];
	for(int i=0;i<4;i++){
		for(int j=1;j<=k;j++){
			int a=x+j*dir[i][0];
			int b=y+j*dir[i][1];
			if(OK(a,b)&&Map[x][y]<Map[a][b]){
				anwser=max(anwser,dfs(a,b));
			}
		}
	}
	dp[x][y]=anwser+Map[x][y];
	return dp[x][y];
}
bool OK(int x,int y){
	if(x<0||x>=n||y<0||y>=n) return false;
	return true;
}
int main()
{
	while(cin>>n>>k){
		if(n==-1&&k==-1) break;
		memset(Map,0,sizeof(Map));
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>Map[i][j];
		}
		cout<<dfs(0,0)<<endl;
	}
 } 
