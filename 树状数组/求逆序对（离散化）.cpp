
#include<bits/stdc++.h>
#define M 500005
using namespace std;
int a[M],d[M],t[M],n;
int lowbit(int x)
{
	return x&-x;
}
void add(int x)//�Ѱ���������Ľ�㶼���� 
{
	while(x<=n)//��Χ 
	{
		t[x]++;
		x+=lowbit(x);
	}
}
int sum(int x)//��ѯ1~X�м������ӽ�ȥ�� 
{
	int res=0;
	while(x>=1)
	{	
		res+=t[x];
		x-=lowbit(x);
	}
	return res;
}
bool cmp(int x,int y)//��ɢ���ȽϺ��� 
{
	if(a[x]==a[y]) return x>y;//����Ԫ����ͬ 
	return a[x]>a[y];//����ԭ���еڼ������� 
}
int main()//402002139
{
	//freopen("in.txt","r",stdin);
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i],d[i]=i;
	
	sort(d+1,d+n+1,cmp);//��ɢ�� 
	
	for(int i=1;i<=n;i++)
	{
		add(d[i]);//��������Ž�ȥ 
		ans+=sum(d[i]-1);//�ۼ� 
	}
	cout<<ans;
	return 0;
}

