#include<iostream>
#include<algorithm>
using namespace std;
int num[100],vis[100]={0},n,paixv[100];
void dfs(int step){//准备排第几个数字 
	if(step==n+1){//这里准备排第n+1元素，那么前面N个元素已经排好了。 
		for(int i=1;i<=n;i++){
			cout<<paixv[i];
		}
		cout<<endl;
		return;
	}
	for(int i=0;i<n;i++){
		if(vis[num[i]]==0){
			paixv[step]=num[i];
			vis[num[i]]=1;
			dfs(step+1);
			
			vis[num[i]]=0;//注意此处的用意。 
		}
	}
}
int main()
{
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>num[i];
		}
		dfs(1);
	}
}
