#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int M=1e5+5;
int a[M],w,b,N,c[M];
void add(int p,int x){
	while(p<=N){
		c[p]+=x;
		p+=p&-p;
	}
}
void range_add(int L,int R){
	add(L,1);
	add(R+1,-1);
}
int ask(int p){
	int res=0;
	while(p>0){
		res+=c[p];
		p-=p&-p;
	}
	return res;
}
int main()
{
	while(cin>>N,N){
		memset(c,0,sizeof(c));
		for(int i=1;i<=N;i++){
			cin>>w>>b;
			range_add(w,b);
		}
		for(int i=1;i<=N;i++){
			if(i==1) cout<<ask(i);
			else cout<<" "<<ask(i);
		}
		cout<<endl;
	}
}
