/*
油田
UVa572 
详情见牛客竞赛 
*/ 


#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<cstdio>
using namespace std;
typedef long long ll;
int m,n;
char Map[105][105];
int biao[105][105];
int dir[8][2]={0,1,1,0,1,1,1,-1,0,-1,-1,0,-1,-1,-1,1};
bool OK(int x,int y){
    if(x<1||x>m||y<1||y>n||Map[x][y]!='@'||biao[x][y]!=0) return false;
    return true;
}
void DFS(int x,int y,int id){
    if(!OK(x,y)) return;
    biao[x][y]=id;
    for(int i=0;i<8;i++){
        int X=x+dir[i][1];
        int Y=y+dir[i][0];
        DFS(X,Y,id);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>m>>n,m&&n){
        memset(Map,0,sizeof(Map));
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++){
                cin>>Map[i][j];
            }
        }
        memset(biao,0,sizeof(biao));
        int cnt=1;
        for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            if(biao[i][j]==0&&Map[i][j]=='@'){
                DFS(i,j,cnt);
                cnt++;
            }
        }
//      for(int i=1;i<=m;i++){
//          for(int j=1;j<=n;j++){
//              cout<<biao[i][j]<<" ";
//          }
//          cout<<endl;
//      }
        cout<<cnt-1<<endl;
    }
}
