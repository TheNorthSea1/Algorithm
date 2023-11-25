#include<iostream>
#include<cstring>
using namespace std;
int a[50005],c[50005];
int lowbit(int x){
	return x&-x;
}
void update1(int i,int val,int N){
	while(i<=N){
		c[i]+=val;
		i+=lowbit(i);
	}
}
int sum(int i){
	int ret=0;
	while(i>0){
		ret+=c[i];
		i-=lowbit(i);
	}
	return ret;
}
int N;

int main()
{
	int T;
	cin>>T;
	for(int qq=1;qq<=T;qq++){
		cout<<"Case "<<qq<<":"<<endl;
		cin>>N;
		memset(c,0,sizeof(c));
		for(int i=1;i<=N;i++){
			cin>>a[i];
			update1(i,a[i],N);
		}
		string w;
		while(cin>>w){
			if(w[0]=='E') break;
			if(w[0]=='Q'){
				int L,R;
				cin>>L>>R;
				cout<<sum(R)-sum(L-1)<<endl;
			}else if(w[0]=='A'||w[0]=='S'){
				int q,e;
				cin>>q>>e;
				if(w[0]=='A'){
					update1(q,e,N);
				}else{
					update1(q,-e,N);
				}
			}
	}
}
}
