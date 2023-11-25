//https://www.luogu.com.cn/problem/P1002/
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
int vis[50][50];
int dir[8][2]={2,1,1,2,-1,2,1,-2,2,-1,-2,1,-1,-2,-2,-1};
int xb,yb;
int mx,my;
ll dp[50][50];
bool OK(int x,int y){
	if(x<0||x>xb||y<0||y>yb) return false;
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>xb>>yb>>mx>>my){
		for(int i=0;i<8;i++){
			int X=mx+dir[i][0];
			int Y=my+dir[i][1];
			if(OK(X,Y)) {
				dp[X][Y]=0;
				vis[X][Y]=1;
		}
		vis[mx][my]=1;
		dp[mx][my]=0;
	}
		int k=0;
		while(!vis[k][0]&&k<=xb){
			dp[k++][0]=1;
		}
		k=0;
		while(!vis[0][k]&&k<=yb){
			dp[0][k++]=1;
		}
		for(int i=0;i<=xb;i++)
		for(int j=0;j<=yb;j++){
			 if(vis[i][j]||i==0||j==0){
				continue;
			}else{
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}
		cout<<dp[xb][yb]<<endl;
	} 
}

