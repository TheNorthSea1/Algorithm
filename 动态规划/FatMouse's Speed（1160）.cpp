/*
利用pre数组，记录路径。
pre[i] = j;意思就是当前这个最优解i是由上一
个最优解j递推出来的 



                                                                           
*/




#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
struct Mose{
	int speed;
	int weight;
	int id;
}mose[1005];
bool cmp(Mose a,Mose b){
	if(a.weight==b.weight){
		return a.speed>b.speed;
	}else{
		return a.weight<b.weight;
	}
}
int main()
{
	int p=1;
	while(cin>>mose[p].weight>>mose[p].speed){
		mose[p].id=p;
		p++;
	}
	sort(mose+1,mose+p,cmp);
	int pre[1005],dp[1005];
	memset(pre,0,sizeof(pre));
	for(int i=0;i<1005;i++){
		dp[i]=1;
	}
	int maxlen=0;
	for(int i=2;i<=p-1;i++){
		for(int j=1;j<i;j++){
			if(mose[j].weight<mose[i].weight&&mose[j].speed>mose[i].speed){
				if(dp[i]<dp[j]+1){
					pre[i]=j;
								//意思就是当前这个最优解i是由上一
         				 	//个最优解j递推出来的
					dp[i]=dp[j]+1;
				}
			}
		}
//		if(dp[i]>maxlen){
//			maxlen=dp[i];
//			maxpos=i;
//		}
	}
	vector<int> vv;
	int maxpos=max_element(dp,dp+p)-dp;
//	cout<<maxpos<<endl;
	while(maxpos!=0){
		vv.push_back(maxpos);
		maxpos=pre[maxpos];
	}
	cout<<vv.size()<<endl;
	for(int i=vv.size()-1;i>=0;i--){
		cout<<mose[vv[i]].id<<endl;
	}
	
}