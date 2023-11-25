#include<iostream>
#include<cmath>
using namespace std;
int D[101][101],recordMax[101][101];
int main()
{
	int i,j,n;
	cin>>n;
	for(i=1;i<=n;i++)
	for(j=1;j<=i;j++)
	cin>>D[i][j];
	for(i=1;i<=n;i++)
	recordMax[n][i]=D[n][i];
	for(i=n-1;i>=1;i--)
	for(j=1;j<=i;j++)
	recordMax[i][j]=max(recordMax[i+1][j],recordMax[i+1][j+1])+D[i][j];
	cout<<recordMax[1][1]<<endl;
 } 
