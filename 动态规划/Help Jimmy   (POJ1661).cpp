#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int N,X,Y,MAX;
const int inf= 20005;
struct Tai{
	int xL,xR;
	int H;
	friend bool operator < (Tai a,Tai b){
		return a.H<b.H;
	}
}T[1005];
int dp[2][1005];//dp[0]代表左，dp[1]代表右。 
void Lefttime(int i){
	int k=i-1;
	while(k>0&&T[i].H-T[k].H<=MAX){
		if(T[i].xL>=T[k].xL&&T[i].xL<=T[k].xR){
			int wangzuo=T[i].xL-T[k].xL;
			int wangyou= T[k].xR-T[i].xL;
			dp[0][i]=T[i].H-T[k].H+min(dp[0][k]+wangzuo,dp[1][k]+wangyou);
			return;
		}else{
			k--;
		}
	}
	if(T[i].H-T[k].H<=MAX){
		dp[0][i]=T[i].H;
	}else{
		dp[0][i]=inf;
	}
} 
void Righttime(int i){
	int k=i-1;
	while(k>0&&T[i].H-T[k].H<=MAX){
		if(T[i].xR>=T[k].xL&&T[i].xR<=T[k].xR){
			int wangzuo=T[i].xR-T[k].xL;
			int wangyou=T[k].xR-T[i].xR;
//			if(i==N+1) cout<<wangzuo<<" "<<wangyou<<endl;
			dp[1][i]=T[i].H-T[k].H+min(dp[0][k]+wangzuo,dp[1][k]+wangyou);
//			if(i==N+1) cout<<dp[0][N]<<" "<<dp[1][N]<<endl;
//			if(i==N+1) cout<<min(dp[0][k]+wangzuo,dp[1][k]+wangyou)<<endl;
			return;
		}else{
			k--;
		}
	}
	//这里要注意 
	if(T[i].H-T[k].H<=MAX){
		dp[1][i]=T[i].H;
	}else{
		dp[1][i]=inf;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		memset(T,0,sizeof(T));
		memset(dp,0,sizeof(dp));
		cin>>N>>X>>Y>>MAX;
		T[0].xL=-20005;
		T[0].xR=20005;
		T[0].H=0;
		for(int i=1;i<=N;i++){
			cin>>T[i].xL>>T[i].xR>>T[i].H;
		}
		T[N+1].xR=X;
		T[N+1].xL=X;
		T[N+1].H=Y;
		sort(T,T+N+1);
		for(int i=1;i<=N+1;i++){
			Lefttime(i);
			Righttime(i);
		} 
//		cout<<dp[1][N]<<endl;
		cout<<min(dp[0][N+1],dp[1][N+1])<<endl;
	}
}
