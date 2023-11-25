#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
using namespace std;
bool judge(int mid);
const int N=1e5+5;
int a[N],n,cow;
int main()
{
	cin>>n>>cow;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int mid,low=0,high=a[n-1];
	while(high-low>1){
		mid=(high+low)/2;
		if(judge(mid))
		low=mid;
		else
		high=mid;
	}
	cout<<low<<endl;										
}
bool judge(int mid){
	int cnt=1,Lp=0,Rp=1;
	while(Rp<n){//此处当Rp大于等于n，时说明找不到适合放cow的牛棚。 
		if(a[Rp]-a[Lp]>=mid){
			Lp=Rp;
			Rp++;
			cnt++;
			if(cnt==cow) return true;
		}else{
			Rp++;
		}
		
	}
	return false;
}

