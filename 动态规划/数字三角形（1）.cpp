#include<iostream>
#include<cmath>
using namespace std;
int D[101][101],recordSum[101][101],n;
int MaxSum(int i,int j){
	if(recordSum[i][j]!=-1) 
	return recordSum[i][j];
	if(i==n){
		recordSum[i][j]=D[i][j];
	}else{
		int x=MaxSum(i+1,j);
		int y=MaxSum(i+1,j+1);
		recordSum[i][j]=max(x,y)+D[i][j];
	}
	return recordSum[i][j];
}
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	for(j=1;j<=i;j++){
		cin>>D[i][j];
		recordSum[i][j]=-1;
	}
	cout<<MaxSum(1,1)<<endl;
	
}








