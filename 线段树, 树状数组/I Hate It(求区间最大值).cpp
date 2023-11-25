#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int inf=2e5+5;
int N,M,A,B,a[inf];
struct SegTree{
	int val;
}segtree[inf<<2];

void pushup(int rt){//注意此处上推的变化 
	segtree[rt].val=max(segtree[rt<<1].val,segtree[rt<<1|1].val);
}

void build(int L,int R,int rt){
	if(L==R){
		segtree[rt].val=a[L];
		return;
	}
	int m=(L+R)>>1;
	build(L,m,rt<<1);
	build(m+1,R,rt<<1|1);
	pushup(rt);
}

//单点修改
void Update(int num,int C,int l,int r,int rt){
	if(l==r){
		segtree[rt].val=C;
		return;
	}
	int m=(l+r)>>1;
	if(num<=m) Update(num,C,l,m,rt<<1);
	else Update(num,C,m+1,r,rt<<1|1);
	pushup(rt);
} 

int Query(int L,int R,int l,int r,int rt){
	if(L<=l&&r<=R){
		return segtree[rt].val;
	}
	int MAX=0;
	int m=(l+r)>>1;
	if(L<=m) MAX=max(Query(L,R,l,m,rt<<1),MAX); 
	if(R>m)	 MAX=max(Query(L,R,m+1,r,rt<<1|1),MAX);
	return MAX;
}

int main()
{    
	char c;
	while(scanf("%d%d",&N,&M)!=EOF){
		memset(segtree,0,sizeof(segtree));
		memset(a,0,sizeof(a));
		for(int i=1;i<=N;i++) scanf("%d",&a[i]);
		build(1,N,1);
		while(M--){
			scanf(" %c%d%d",&c,&A,&B);
			if(c=='Q'){
				cout<<Query(A,B,1,N,1)<<endl;
			}else{
				Update(A,B,1,N,1);
			}
		}
	}
}
