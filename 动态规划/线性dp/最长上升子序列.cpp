#include<iostream>
#include<cmath>
#include<algorithm> 
using namespace std;
const int N=1e5+1;
int a[N],record[N];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		record[i]=1;
	}
	for(int i=2;i<=n;i++)
	for(int j=1;j<i;j++){
		if(a[j]<a[i]){
			record[i]=max(record[i],record[j]+1);
		}
	}
	cout<<*max_element(record+1,record+n+1)<<endl;
	cout<<max_element(record+1,record+n+1)-record;
	
}
