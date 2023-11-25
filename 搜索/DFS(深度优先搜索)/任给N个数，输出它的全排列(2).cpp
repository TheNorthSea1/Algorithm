#include<iostream>
using namespace std;
int vis[100]={0},num[100],ans[100],N;
void DFS(int step){
	if(step==N+1){
		for(int i=1;i<=N;i++){
			cout<<ans[num[i]]; 
		}
		cout<<endl;
		return;
	}
	for(int i=1;i<=N;i++){
		if(vis[i]==0){
			num[step]=i;
			vis[i]=1;
			
			DFS(step+1);
			
			vis[i]=0;
		}
		
	}
}
int main()
{
	while(cin>>N){
		for(int i=1;i<=N;i++){
			cin>>ans[i];
		}
		DFS(1);
	}
 } 
