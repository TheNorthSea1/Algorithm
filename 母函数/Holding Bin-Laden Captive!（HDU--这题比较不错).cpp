#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<cstdio>
using namespace std;
typedef long long ll;
const int maxn=100005;
int c1[maxn],c2[maxn];
int elem[3]={1,2,5};
int main()
{
	ios::sync_with_stdio(false);
	int val[3];
	while(cin>>val[0]>>val[1]>>val[2]){
		if(val[0]==0&&val[1]==0&&val[2]==0) break;
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		
		int sum=val[0];//ע�� 
		
		for(int i=0;i<=sum;i++) c1[i]=1;
		
		for(int i=2;i<=3;i++){
			for(int j=0;j<=sum;j++){
				for(int k=0;k<=elem[i-1]*val[i-1];k+=elem[i-1]){
					c2[j+k]=c1[j];
				}
			}
			sum+=elem[i-1]*val[i-1];// 
			for(int t=0;t<=sum;t++){
				c1[t]=c2[t];
				c2[t]=0;
			}
		}
		for(int i=0;i<=sum+1;i++){//ע������Ϊʲô��1 ����Ϊ����0����sum ����ʵ�֣���ôӦ�����sum+1�������û�д��ˡ� 
			if(!c1[i]){
				cout<<i<<endl;
				break;
			}
		}
	}
}

