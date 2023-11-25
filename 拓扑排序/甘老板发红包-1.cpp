#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
const int inf=INT_MAX;
int n,m,flag=0;
int dp[10005],in[10005];
vector<int> Map[10005];
vector<int> ans;
void init(){
	for(int i=0;i<=n;i++){
		dp[i]=0;
		Map[i].clear();
	}
	ans.clear();
}
void topsort(){
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(in[i]==0){
			dp[i]=888;
			q.push(i);
		} 
		
	}
	while(!q.empty()){
		int pos=q.front();
		q.pop();
		ans.push_back(pos);
		for(int i=0;i<Map[pos].size();i++){
			int pp=Map[pos][i];
			dp[pp]=max(dp[pp],dp[pos]+1);
			in[pp]--;
			if(in[pp]==0) q.push(pp);
		} 
	}
	if(ans.size()!=n) flag=1;
	
}
int main()
{
	while(cin>>n>>m){
		init();
		flag=0;
		memset(in,0,sizeof(in));
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			Map[b].push_back(a);
			in[a]++;
		}
		topsort();
		int sum=0;
//		cout<<in[1]<<in[2]<<endl;
		if(flag==1){
			cout<<-1<<endl;
		}else{
			for(int i=1;i<=n;i++){
			sum+=dp[i];
			}
			cout<<sum<<endl;
		}
	}
}
