#include<iostream>
#include<algorithm>
using namespace std;
void Quicksort(int a[],int left,int right){
	if(left>=right) return;
	int l,r,base;
	l=left,r=right;
	base=a[left];//把最左边的数做基数
	while(l<r){
		while(a[r]>=base&&l<r) r--;
		while(a[l]<=base&&l<r) l++;
		swap(a[r],a[l]);
	} 
	a[left]=a[l];
	a[l]=base;
	Quicksort(a,left,r-1);
	Quicksort(a,r+1,right);
}
int main()
{
	int a[5]={3,0,1,9,4};
	Quicksort(a,0,4);
	for(int i=0;i<5;i++){
		if(i==0)
		cout<<a[i];
		else
		cout<<","<<a[i];
	}
}
