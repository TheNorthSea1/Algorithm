#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
struct Rule{
	bool operator()(const int &a1,const int &a2)const{
		return a1%10<a2%10;
	}
};
//此处Rule定义规则为按个位数从小到大排序； 
int main()
{
	int a[]={12,45,3,98,21,7};
	sort(a,a+6,Rule());
	for(int i=0;i<6;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"result:"<<binary_search(a,a+6,7)<<endl;
	cout<<"result:"<<binary_search(a,a+6,8,Rule())<<endl;
	return 0;
}
