#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
int main()
{
	multiset<int> st;
	int a[10]={1,14,12,13,13,7,21,19,8,8};
	for(int i=0;i<10;i++)
		st.insert(a[i]);
	multiset<int>::iterator p;
	for(p=st.begin();p!=st.end();p++)
		cout<<*p<<",";
		cout<<endl;
	p=st.find(22);//Ѱ��multiset���Ƿ���22�����û�з���end������ 
	if(p==st.end())
		cout<<"no found"<<endl;
	st.insert(22);
	p=st.find(22);//����ҵ���22����pָ��22�� 
	if(p==st.end())
		cout<<"not found"<<endl;
	else
		cout<<"found"<<" "<<*p<<endl;			
	return 0;	
 } 
