/*
https://ac.nowcoder.com/acm/problem/219919

*/ 

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
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
int x[5],y[5];
int  t;
double xie(int a,int b){
	return (y[a]-y[b])*1.0/(x[a]-x[b]);
}

bool pan(int a,int b,int c,int d){
	return abs(x[a]-x[b])==abs(x[c]-x[d])&&abs(y[a]-y[b])==abs(y[c]-y[d]);
}

bool ju(int a,int b){
	if(x[a]==x[b]&&y[a]==y[b])  return true;
	return false;
}



int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		for(int i=1;i<=4;i++) cin>>x[i]>>y[i];
		
		if(ju(1,2)||ju(1,3)||ju(1,4)||ju(2,3)||ju(2,4)||ju(3,4)){
			puts("NO");
			continue;
		}
		
		
		if(xie(1,2)==xie(1,3)||xie(1,2)==xie(1,4)||xie(1,3)==xie(1,4)||xie(2,3)==xie(2,4)){
			puts("NO");
			continue;
		}    
		
		if(pan(1,2,3,4)||pan(1,3,2,4)||pan(1,4,2,3)){
			puts("YES");
		}else{
			puts("NO");
		}
		
	}
}

