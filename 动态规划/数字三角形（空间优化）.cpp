#include<iostream>
#include<cmath>
using namespace std;
int n,*maxSum,D[101][101];
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	for(j=1;j<=i;j++)
	cin>>D[i][j];
	maxSum=D[n];
	for(i=n-1;i>=1;i--)
	for(j=1;j<=n;j++)
	maxSum[j]=max(maxSum[j],maxSum[j+1])+D[i][j];
	cout<<maxSum[1]<<endl;
	
 } 
