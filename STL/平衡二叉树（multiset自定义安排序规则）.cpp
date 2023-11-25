#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
struct Rule1{
	bool operator()(const int &a,const int &b){
		return a%10<b%10;
	}
};
int main()
{
	multiset<int,greater<int>> st;
	int a[10]={1,14,12,13,7,13,21,19,8,8};
	for(int i=0;i<10;i++)
		st.insert(a[i]);
	multiset<int,greater<int>>::iterator p;
	for(p=st.begin();p!=st.end();p++){
		cout<<*p<<",";
	}
	cout<<endl;
	multiset<int,Rule1> st1;
	for(int i=0;i<10;i++)
		st1.insert(a[i]);
	multiset<int,Rule1>::iterator s;
	for(s=st1.begin();s!=st1.end();s++){
		cout<<*s<<",";
	}	
	cout<<endl;
}
