/*
https://www.luogu.com.cn/problem/P2392
*/

#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
int a[4],dp[1000],kemu[100],j;
int main()
{
	for(int i=0;i<4;i++) cin>>a[i];
	int ans=0;
	for(int i=0;i<4;i++){
		int sum=0;
		for(j=0;j<a[i];j++){
			cin>>kemu[j];
			sum+=kemu[j];
		}
		for(int t=0;t<j;t++){
			for(int k=sum/2;k>=kemu[t];k--){
				dp[k]=max(dp[k],dp[k-kemu[t]]+kemu[t]);
			}
		}
		ans+=(sum-dp[sum/2]);//先求出一半容量，所能达到的最大承载量。 
		memset(dp,0,sizeof(dp));
	}
	cout<<ans<<endl;
}

