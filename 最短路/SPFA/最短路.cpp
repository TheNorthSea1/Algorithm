#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef long long ll;
const int inf=0x7FFFFFFF;
const int p=2e4+5;
struct Node{
	int pos,len;
	Node(int pos,int len): pos(pos),len(len){}
	friend bool operator <(Node a,Node b){
		return a.len>b.len;
	}
};
vector<Node> g[p];
int n,m;
int dist[p],vis[p];
void init(){
	for(int i=0;i<p;i++){
		vis[i]=0;
		dist[i]=inf;
	}
}
void spfa(){
    dist[1] = 0;
    queue<Node> q;
    q.push(Node(1,0));
    while(!q.empty()){
        Node u = q.front();
        q.pop();
        vis[u.pos] = 0;       //ע��˴���dijst������ 
//		if(vis[u.pos]) continue;
//		vis[u.pos]=1;
        for(int i=0;i<g[u.pos].size();i++){
            int v=g[u.pos][i].pos;
            int w=g[u.pos][i].len;
            if(dist[v]>dist[u.pos]+w){
                dist[v]=dist[u.pos]+w;	//����Χ�ĵ㶼���� 
                if(!vis[v]){            //ע������vis��λ�ã����������û�õ㣬����ӡ� 
                    vis[v] = 1;
                    q.push(Node(v,0));//ע�� 
                }
            }
        }
    }
}
int main()
{
		scanf("%d%d",&n,&m);
		init();
		for(int i=0;i<m;i++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			g[a].push_back(Node(b,c));
//			g[b].push_back(Node(a,c));
		}
		spfa();
		for(int i=2;i<=n;i++){
			cout<<dist[i]<<endl;
		}
}







