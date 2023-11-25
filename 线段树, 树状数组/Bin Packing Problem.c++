#include<bits/stdc++.h>
using namespace std;
#define ms(__x__,__val__) memset(__x__, __val__, sizeof(__x__))
#define FI(__x__,__y__) for(int i=__x__;i<__y__;i++)
#define _FI(__x__,__y__) for(int i=__x__;i >= __y__ ;i--)
#define FJ(__x__,__y__) for(int j=__x__;j<__y__;j++)
#define all(_x_) _x_.begin(),_x_.end()
#define pb(__x__) push_back(__x__)
#define IOS ios::sync_with_stdio(0);cin.tie(0); cout.tie(0)
#define debug(__x__,__y__) cout<<__x__<<": "<<__y__<<endl

// #define int ll
typedef long long ll;

const int maxn = 1e6 + 5;
#define inf 0x3f3f3f3f

int N,C;

struct Node{
		int L,R;
    int val;
    int tag;

}t[maxn<<2];
int a[maxn];
void pushup(int rt){
	t[rt].val = max(t[rt<<1].val,t[rt<<1|1].val);
}

void pushdown(int rt){
	if(t[rt].tag){
		t[rt<<1].tag += t[rt].tag;  //
		t[rt<<1|1].tag += t[rt].tag;  //
		t[rt<<1].val += t[rt].val;
		t[rt<<1|1].val += t[rt].val;
		t[rt].tag = 0;
	}
}


void build(int L,int R,int rt){
	t[rt].L = L,t[rt].R = R;
	t[rt].tag = 0;
	if(L == R){
		t[rt].val = C;// 初始化容量
		return;
	}

	int m = L + R>>1;
	build(L,m,rt<<1);
	build(m+1,R,rt<<1|1);

	pushup(rt);
}

void update(int pos,int rt,int val){
	int x = t[rt].L,y = t[rt].R;
	if(x == y){
		t[rt].val += val;

		t[rt].tag += val;
		return;
	}
	int m = x + y >>1;
	pushdown(rt);

	if(pos<=m){
		update(pos,rt<<1,val);
	}else{
		update(pos,rt<<1|1,val);
	}
	pushup(rt);
}

int query(int rt,int val){
	int x = t[rt].L, y = t[rt].R;
	if(x == y){
		return x;
	}

	pushdown(rt);

	if(val <= t[rt<<1].val){
		return query(rt<<1,val);
	}else{
		return query(rt<<1|1,val);
	}
}



int main()
{
 	IOS;
    int _;
	cin>>_;
	while(_--){
		cin>>N>>C;
		build(1,N,1);
		int pos = 1;
		FI(1,N+1){
			cin>>a[i];
		}
		int Max_bot1 = 0;
		FI(1,N+1){
			pos = query(1,a[i]);
			Max_bot1 = max(Max_bot,pos);
			update(pos,1,-a[i]);
		}
		
		int Max_bot2 = 0;
		map<int,int> mp;
		mp[C] = 1;
		for(int i =1;i<=N;i++){
			auto u = mp.lower_bound(a[i]);
			if(u == mp.end()){  //当前没有可以容纳 a[i] 物品的容器

				mp[C - a[i]]++;
			}else{
				mp[u->first - a[i]]++;
				mp[u->first]--;
				if(mp[u->first] == 0){ // 等于0说明这个类型的容器已经没了，变成其他的了
					mp.erase(u);
				}
			}
		}

		for(auto u : mp){
			Max_bat2 += u.second;
		}

		cout<<Max_bat1<<" "<<Max_bat2<<endl;

		
	}



}
