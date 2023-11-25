#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	int L,R;
}node[50];
int behind[500],mid[500];

vector<int> ceng[100];

int MAX = 0;
void build(int Lb,int Rb,int Lmid,int Rmid,int level){
	if(Lb>Rb || Lmid > Rmid ) return;
	
	int root = behind[Rb];
	
	ceng[level].push_back(root); //将每一层的节点放入对应的数组中

	MAX = max(MAX,level);
	int pos = Lmid;
	
	while(mid[pos] != root) pos++;
	
	int len = pos - Lmid;
	build(Lb,Lb + len -1,Lmid,pos-1,level+1);
	build(Lb+len,Rb-1,pos+1,Rmid,level+1);
	
	
}

int main(){
	int N;
	cin>>N;

	for(int i = 0;i<N;i++) cin>>mid[i];
	for(int i = 0;i<N;i++) cin>>behind[i];
	
	
	build(0,N-1,0,N-1,0);
	
	cout<<"R: ";
	for(int i = 0;i<=MAX;i++){
		if(i!=0) cout<<" ";
		cout<<ceng[i].back();
	}
	cout<<endl;
	cout<<"L: ";
	for(int i = 0;i<=MAX;i++){
		if(i!=0) cout<<" ";
		cout<<ceng[i].front();
	}
	
	
}
/*

后序: 
中序: 
8
2 3 1 8 5 7 6 4
1 2 3 4 8 5 6 7


L: 4 1 3 2  (从左看)
R: 4 6 7 8  (从右看)


*/