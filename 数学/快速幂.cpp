#include<iostream>
#include<algorithm>
using namespace std;
//�ǵݹ�ʵ�� 
int power(int a,int n){
	int ans=1;
	while(n){
		if(n%2==1) ans=ans*a;
		a*=a;
		n/=2;
	}
	return ans;
}
//�ݹ�ʵ��
int power1(int a,int n){
	int ans;
	if(n==0) ans=1;
	else{
		ans=power1(a*a,n/2);
		if(n%2==1) ans*=a;
	}
	return ans;
} 
int main()
{
	int a,n;
	cin>>a>>n;
	cout<<power(a,n)<<endl;
	cout<<power1(a,n)<<endl;
 } 
