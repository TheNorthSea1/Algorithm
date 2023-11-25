#include<bits/stdc++.h>
using namespace std;
const int maxn = 30 * 100;
struct Node{
	int data;
	int L,R;
}node[maxn];
int behind[maxn],mid[maxn];

vector<int> vt[maxn];  //存每一层的节点

int MAX = 0;
int N;

int  build(int Lb,int Rb,int Lmid,int Rmid,int  root,int level ){
	if(Lb>Rb || Lmid>Rmid) return -1;
	
	MAX = max(MAX,level);
	
	vt[level].push_back(behind[Rb]);// 层序遍历可以不用bfs直接在建树的时候存
	
	node[root].data = behind[Rb];
	int pos = 0;
	while(mid[pos] != behind[Rb]) pos++;
	int len = pos - Lmid;
	
	node[root].L = build(Lb,Lb+len-1,Lmid,pos-1,root<<1,level+1);
	node[root].R =  build(Lb+len,Rb-1,pos+1,Rmid,root<<1|1,level+1);
	
	return root;
}

void bfs(){
	queue<Node> q;
	q.push(node[1]);
	
	int flag = 0;
	while(!q.empty()){
		Node cur = q.front();q.pop();
		if(!flag){
			flag = 12;
			cout<<cur.data;
		}else{
			cout<<" "<<cur.data;
		}
		
		if(cur.L != -1) q.push(node[cur.L]);
		if(cur.R != -1) q.push(node[cur.R]);
		
	}
}


int main(){
	
	cin>>N;
	for(int i = 0;i<N;i++) cin>>behind[i];
	for(int i = 0;i<N;i++) cin>>mid[i];
	build(0,N-1,0,N-1,1,1);
	
	int flag = 0;
	
//	for(int i = 1;i<=MAX;i++){
//		for(int j = 0;j<vt[i].size();j++){
//			if(!flag){
//				cout<<vt[i][j];
//				flag = 1;
//			}else{
//				cout<<" "<<vt[i][j];
//			}
//		}
//	}
	bfs();  // 层序遍历可以不用bfs直接在建树的时候存
//	cout<<node[1].L<<endl;
	
		
}