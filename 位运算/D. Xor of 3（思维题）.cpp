/*
https://codeforces.com/contest/1573/problem/D
题目分析：
先考虑变换前后的不变量，首先每次变换均不会改变序列的奇偶性，
要么少两个 \(1\) 要么多两个 \(1\) ，
所以原序列若存在奇数个 \(1\) 则无解。


偶数个 \(1\) 情况下，考虑一段连续的 \(1\) ：
	1.如果是偶数个 \(1\) ，由于本题序列的奇偶不变性，一定可以将这段 \(1\) 全消为 \(0\)
	
	2.如果是奇数个 \(1\) ，那么不能靠自己消完，所以要往后每次把两个 \(0\) 变成 \(1\) ，
	直到遇到 \(101\) 这种情况，把 \(101\) 变成 \(000\) 后，前面的 \(1\) 只有偶数个，
	即转换为了上述情况，就可以消完了



最后特判一下 \(0、0、0 \cdots 1、1、1\) 情况就好，由于末尾段 \(1\) 的个数必为偶数个，
所以前面只要存在 \(0\) 就可以全部消完，那么唯一无解的情况下即是序列转化为了全 \(1\) 序列（如 \([1,0,0,1]\) ）。

*/


#include<bits/stdc++.h>
#define ms(__x__,__val__) memset(__x__, __val__, sizeof(__x__))
#define FI(__x__,__y__) for(int i=__x__;i<__y__;i++)
#define FJ(__x__,__y__) for(int j=__x__;j<__y__;j++)
#define pb push_back
using namespace std;
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		int cnt=0;
		
		FI(1,n+1) cin>>a[i],cnt+=a[i];
		
		if(cnt&1){  //如果序列 （1） 的个数是奇数个，那就不可能OK 
			cout<<"NO\n";
			continue;
		}
		
		cnt=0;
		vector<int> v;
		for(int i=1;i<=n;i++){
			if(a[i]){
				cnt++;
			}else if(cnt&1){
				
				if(a[i+1]){ // 101
					a[i-1]=a[i+1]=0;
					for(int j=i-1;j>=i-cnt;j-=2){
						v.pb(j),a[j]=a[j+1]=0;	
					}
					cnt=0;
				}else{ //100;
					v.pb(i-1);   //此处的操作就会把这三个数都变成 1 
					a[i]=a[i+1]=1;
					cnt++;
				}
			}else{ //连续1的个数是偶数个 
				for(int j=i-2;j>=i-cnt;j-=2){
					v.pb(j),a[j]=a[j+1]=0;
				}
				cnt=0;
			}
		}
	
		if(cnt){
			if(cnt==n){
				cout<<"NO\n";
				continue;
			}else{ //最后到末尾连续的1 一定为偶数个。因为总共为偶数个1，如果前面的1 如果是奇数则整个数列会变成1 
				for(int j=n-cnt;j<=n-2;j+=2){//所以 cnt!= n 则表示前面是偶数个。 
					v.pb(j);
				}
			}
		}
		cout<<"YES\n";
		cout<<v.size()<<"\n";
		for(int i=0;i<v.size();i++){
			if(i!=0) cout<<" ";
			cout<<v[i];
		}
		if(v.size())	cout<<"\n";	
	
	}
}
