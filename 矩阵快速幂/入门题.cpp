/*
http://acm.hdu.edu.cn/showproblem.php?pid=2604
1.µÝÍÆË¼Î¬
f(n)=f(n-1)+f(n-3)+f(n-4);

*/


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
ll L,mod;
struct Mat{
	ll a[5][5];
	Mat(ll e=0){
		for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		a[i][j]=e*(i==j);
	}
	Mat mul(Mat A,Mat B){
		Mat ans(0);
		for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		for(int k=1;k<=4;k++)
		ans.a[i][j]=(ans.a[i][j]+(A.a[i][k]*B.a[k][j]))%mod;
		return ans;
	}
	Mat power(Mat A,ll b){
		Mat ans(1);
		while(b){
			if(b&1) ans=ans.mul(ans,A);
			A=mul(A,A);
			b>>=1;
		}
		return ans;
	}
}; 
int main()
{
//	ios::sync_with_stdio(false);
	
	while(cin>>L>>mod){
	Mat tmp;
	int f[5]={0,9,6,4,2};
	tmp.a[1][1]=1,tmp.a[1][3]=1,tmp.a[1][4]=1;
	tmp.a[2][1]=1;
	tmp.a[3][2]=1;
	tmp.a[4][3]=1;
		if(L<=4){
		ll w=0;
			if(L==1){
				w=2;	
			}else if(L==2){
				w=4;
			}else if(L==3){
				w=6;
			}else{
				w=9;
			}
			cout<<w%mod<<endl;
			continue;
		}
		tmp=tmp.power(tmp,L-4);
		ll ans=0;
		for(int i=1;i<=4;i++) ans=(ans+tmp.a[1][i]*f[i])%mod;
		cout<<ans%mod<<endl;
//		for(int i=1;i<=4;i++){
//			for(int j=1;j<=4;j++){
//				cout<<tmp.a[i][j]<<" ";
//			}
//			cout<<endl;
//		}
		
	}
}

