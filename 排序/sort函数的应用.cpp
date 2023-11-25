#include<iostream>
#include<algorithm>
#include<set>
#include<cstring>
using namespace std;
int main()
{
	int a[]={2,0,1,7,9,6};
	sort(a,a+6);//从小到大 
	for(int i=0;i<6;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	sort(a,a+6,greater<int>());//从大到小 
	for(int i=0;i<6;i++){
		cout<<a[i]<<" ";
	}
	return 0;
 } 
