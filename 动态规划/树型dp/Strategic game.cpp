
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
#define ms(__x__,__val__) memset(__x__, __val__, sizeof(__x__))
#define FI(__x__,__y__) for(int i=__x__;i<__y__;i++)
#define FJ(__x__,__y__) for(int j=__x__;j<__y__;j++)
#define shu(__x__) int __x__;cin>>__x__
#define SC(__x__) scanf("%d",&__x__)
#define eps 1e-6
#define inf 0x7FFFFFFF
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn = 1600;
const int mod = 1e9+7;
inline int gcd(int a,int b){
	return b ? gcd(b , a%b) :a;
}
int n;
int dp[maxn][2];
/*
dp[i][1]  ��ʾ i �����������һ��ʿ��
dp[i][0]  ��ʾ i �����û������ʿ��



*/


vector<int> G[maxn];

void dfs(int pos,int pre){
	dp[pos][1]=1;
	dp[pos][0]=0;
	for(int i=0;i<G[pos].size();i++){
		int child = G[pos][i];
		
		if(child == pre) continue;
		dfs(child,pos);
		//״̬ת��
		 
		dp[pos][1]+=min( dp[child][1] , dp[child][0] ); // dp[x][1]=1+��min(dp[i][0],dp[i][1])//x�Ϸ���ʿ����x�Ķ����ǿɷſɲ���
		
		dp[pos][0]+=dp[child][1];//dp[x][0]=��dp[i][1]//���x����ʿ����x�Ķ��ӱ����
	}
}


int main()
{
// 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

	while(cin>>n){
		ms(dp,0);
		FI(0,maxn) G[i].clear();
		while(n--){
			int fa,m,x;
			scanf("%d:(%d)",&fa,&m);
			while(m--){
				SC(x);
				G[fa].push_back(x);
				G[x].push_back(fa);
			}
		}
		dfs(0,-1);//��� 0 ������� 
		cout<<min(dp[0][0],dp[0][1])<<endl;
	}
}

