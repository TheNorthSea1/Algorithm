#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn = 1e5 + 5;
struct Node{
	int fa;
	int relation;  //该节点与 根节点的关系 
}bin[maxn];

//  x--> y 0    表示两者的关系为同类；

//  x-->y 1     表示两者的关系为 x被 根节点 吃;

//  x-->y 2      表示两者为  x  吃  根节点; 

int find(int x){
	int y;
	
	if(x!=bin[x].fa){
		y=bin[x].fa;
		bin[x].fa=find(y);
		bin[x].relation = (bin[x].relation+bin[y].relation) % 3; //  x -> R == x->y + y->R  
	}
	
	return bin[x].fa;
}

void merge(int x,int y,int opt){
	int Rx=find(x);
	int Ry=find(y);
	bin[Ry].fa = Rx;
	if(opt==1){
		bin[Ry].relation = (bin[x].relation - bin[y].relation +3) %3;
	}else{
		bin[Ry].relation = (1 + bin[x].relation - bin[y].relation +3) %3;
	}
	
}



int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	for(int i=0;i<maxn;i++){
		bin[i].fa=i;
		bin[i].relation=0;
	}
	int N,K;
	cin>>N>>K;
	int ans=0;
	
	while(K--){
		int opt,a,b;
		cin>>opt>>a>>b;
		if(a>N||b>N||(a==b&&opt==2)){
			ans++;
			continue;
		}
		
		if(opt==1){
			if(find(a)==find(b)){
				if(bin[a].relation!=bin[b].relation){
					ans++;
					continue;
				}
			}
			
		}else{
			if(find(a)==find(b) ){
				int w=(bin[a].relation-bin[b].relation+3)%3; //利用  a->R,b->R 来得到 a->b 之间的关系 
				if(w!=2){
					ans++;
					continue;
				}
			}
		}
		merge(a,b,opt);
	}
	
	cout<<ans<<endl; 





}

