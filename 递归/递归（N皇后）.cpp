#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n;
int queenPos[100];
void Nqueen(int k);
int main()
{
	cin>>n;
	Nqueen(0);
	return 0;
}
void Nqueen(int k){
	int i;
	if(k==n){
		for(i=0;i<n;i++){
			cout<<queenPos[i]+1<<" ";
		}
		cout<<endl;
		return;
	}
	for(i=0;i<n;i++){
		int j;
		for(j=0;j<k;j++){
			if(queenPos[j]==i||abs(queenPos[j]-i)==abs(k-j))
			break;
		}
		if(j==k){
			queenPos[k]=i;
			Nqueen(k+1);
		}
	}
} 










