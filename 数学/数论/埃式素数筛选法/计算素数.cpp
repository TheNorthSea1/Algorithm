#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<cstdio>
#define test(a) cout << "-----" << a << "-----" << '\n'
#define ms(__x__,__val__) memset(__x__, __val__, sizeof(__x__))
#define Fi(__x__,__y__) for(int i=__x__;i<__y__;i++)
#define Fj(__x__,__y__) for(int j=__x__;j<__y__;j++)
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn = 1e5 + 5;

int main()
{	
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
		//�� С�ڵ��� n ���������� 
	 int n;
	 cin>>n;
	 int vis[5000];//���ڼ����Ƿ�Ϊ����
	 ms(vis,0);
	 
	 int m=sqrt(n+0.5);
	 for(int i=2;i<=m;i++){
	 	if(!vis[i]){ //��� i �����أ���ô���ı������������� 
	 		for(int j=i*i;j<=n;j+=i){
	 			vis[j]=1;
			 }
		 }
	 } 

	int ans=0;
	for(int i=2;i<=n;i++) if(!vis[i]) cout<<i<<endl;
	
	cout<<ans<<endl; 


}

