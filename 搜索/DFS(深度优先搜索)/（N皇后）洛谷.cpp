#include<iostream>
#include<cmath>
using namespace std;
int n,queen[20], cnt=0,flag=0,vis[20]={0};//�ص�˴���vis��� 
void Queen(int k){
	if(k==n){
		cnt++;
		if(cnt<=3){
			for(int i=0;i<n;i++){
			if(i==0){
				cout<<queen[i]+1;
			}else{
				cout<<" "<<queen[i]+1;
				}
			}
			cout<<endl;
		}
	}
	int i,j;
	for(i=0;i<n;i++){
		if(vis[i]==1) continue;//�˴���֦��������һ�е�ֱ�������� 
		for(j=0;j<k;j++){
			if(queen[j]==i||abs(queen[j]-i)==abs(k-j))
			break;
		}
		if(j==k){
		vis[i]=1;//�ص� 
		queen[k]=i;
		Queen(k+1);
		vis[i]=0;//�ص� 
	   }
	}
}
int main()
{
	cin>>n;
	Queen(0);
	cout<<cnt;
}
