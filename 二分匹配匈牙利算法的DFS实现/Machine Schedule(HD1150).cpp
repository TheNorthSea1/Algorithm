#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int Max=510;
int LN,RN;//分别为左顶点数，右顶点数。
int g[Max][Max]; 
int linker[Max];//存右点的对象
bool used[Max];
bool dfs(int L){
	for(int R=0;R<RN;R++){
		if(g[L][R]==true&&used[R]==false){
			used[R]=true;
			if(linker[R]==-1||dfs(linker[R])){
				linker[R]=L;
				return true;
			}
		}
	}
	return false;
} 
int hungary(){
	int cnt=0;
	memset(linker,-1,sizeof(linker));
	for(int L=0;L<LN;L++){
		memset(used,false,sizeof(used));
		if(dfs(L)) cnt++;
	}
		return cnt;
}
int main(){
	int k;
	while(cin>>LN,LN){
		cin>>RN>>k;
		memset(g,0,sizeof(g));
		int id,L,R;
		while(k--){
			cin>>id>>L>>R;
			if(L!=0&&R!=0)
			g[L][R]=1;
		}
		cout<<hungary()<<endl;
	}
	
}





