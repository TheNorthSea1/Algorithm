
#include<bits/stdc++.h>
#define M 500005
using namespace std;
int a[M],d[M],t[M],n;
int lowbit(int x)
{
	return x&-x;
}
void add(int x)//把包含这个数的结点都更新 
{
	while(x<=n)//范围 
	{
		t[x]++;
		x+=lowbit(x);
	}
}
int sum(int x)//查询1~X有几个数加进去了 
{
	int res=0;
	while(x>=1)
	{	
		res+=t[x];
		x-=lowbit(x);
	}
	return res;
}
bool cmp(int x,int y)//离散化比较函数 
{
	if(a[x]==a[y]) return x>y;//避免元素相同 
	return a[x]>a[y];//按照原序列第几大排列 
}
int main()//402002139
{
	//freopen("in.txt","r",stdin);
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i],d[i]=i;
	
	sort(d+1,d+n+1,cmp);//离散化 
	
	for(int i=1;i<=n;i++)
	{
		add(d[i]);//把这个数放进去 
		ans+=sum(d[i]-1);//累加 
	}
	cout<<ans;
	return 0;
}

