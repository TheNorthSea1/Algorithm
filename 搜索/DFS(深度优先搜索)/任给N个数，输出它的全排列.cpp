#include<iostream>
#include<algorithm>
using namespace std;
int num[100],vis[100]={0},n,paixv[100];
void dfs(int step){//׼���ŵڼ������� 
	if(step==n+1){//����׼���ŵ�n+1Ԫ�أ���ôǰ��N��Ԫ���Ѿ��ź��ˡ� 
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
			
			vis[num[i]]=0;//ע��˴������⡣ 
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
