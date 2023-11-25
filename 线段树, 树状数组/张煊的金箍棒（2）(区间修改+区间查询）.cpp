#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int inf=1e5+5;
int N,X,Y,Z;
struct SegTree{
	int val,lazy;
}segtree[inf<<2];
void pushup(int rt){
	segtree[rt].val=segtree[rt<<1].val+segtree[rt<<1|1].val;
}
//建立线段树 
void build(int L,int R,int rt){
	segtree[rt].lazy=0;
	if(L==R){
		segtree[rt].val=1;
		return;
	}
	int m=(L+R)>>1;
	build(L,m,rt<<1);
	build(m+1,R,rt<<1|1);
	pushup(rt);	
} 
//下推操作
void pushdown(int rt,int Len,int Ren){
	if(segtree[rt].lazy){
		segtree[rt<<1].lazy=segtree[rt].lazy;
		segtree[rt<<1|1].lazy=segtree[rt].lazy;
		segtree[rt<<1].val=segtree[rt].lazy*Len;
		segtree[rt<<1|1].val=segtree[rt].lazy*Ren; 
	}
	segtree[rt].lazy=0;
} 
//区间修改
void Update(int L,int R,int C,int l,int r,int rt){
	if(L<=l&&r<=R){
		segtree[rt].val=C*(r-l+1);
		segtree[rt].lazy=C;
		return;
	}
	int m=(l+r)>>1;
	pushdown(rt,m-l+1,r-m);
	if(L<=m) Update(L,R,C,l,m,rt<<1);
	if(R>m) Update(L,R,C,m+1,r,rt<<1|1);
	pushup(rt);
} 
//区间查询
int Query(int L,int R,int l,int r,int rt){
	if(L<=l&&r<=R) return segtree[rt].val;
	if(l<L||r>R) return 0;
	int m=(l+r)>>1;
	pushdown(rt,m-l+1,r-m);
	return Query(L,R,l,m,rt<<1)+Query(L,R,m+1,r,rt<<1|1);
} 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&N); 
		build(1,N,1);
		int Q;
		scanf("%d",&Q);
		while(Q--){
			scanf("%d%d%d",&X,&Y,&Z);
			Update(X,Y,Z,1,N,1);
		}
		cout<<Query(1,N,1,N,1)<<endl;
	}
}
