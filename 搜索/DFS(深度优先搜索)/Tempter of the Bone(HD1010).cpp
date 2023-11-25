#include<iostream>
#include<cmath>
using namespace std;
char Map[9][9];
int x,y,time,si,sj,di,dj;
bool escape;
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
void DFS(int si,int sj,int cnt);
int main()
{
	while(cin>>x>>y>>time){
		if(x==0&&y==0&&time==0) break;
		int wall=0;
		for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++){
			cin>>Map[i][j];
			if(Map[i][j]=='S'){//记入起始位置。 
				si=i;
				sj=j;
			}else if(Map[i][j]=='D'){//记入目标位置。 
				di=i;
				dj=j;
			} else if(Map[i][j]=='X'){
				wall++;
			}
		}
		if(x*y-wall<=time){
			cout<<"NO"<<endl;
			continue;
		}
		escape=0;
		Map[si][sj]='X';
		DFS(si,sj,0);
		if(escape){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}
void DFS(int si,int sj,int cnt){
	int i,temp;
	if(si>x||sj>y||si<=0||sj<=0) return;
	if(cnt==time&&si==di&&sj==dj) escape=1;//逃离成功 
	if(escape) return;
	
	temp=(time-cnt)-abs(si-di)-abs(sj-dj);
	
	if(temp<0||temp%2==1) return;//没看懂temp%2==1剪枝的用意	
								 //还有要注意temp<0 
	for(i=0;i<4;i++){//四个方向 
		if(Map[si+dir[i][0]][sj+dir[i][1]]!='X'){
			Map[si+dir[i][0]][sj+dir[i][1]]='X';
			
			DFS(si+dir[i][0],sj+dir[i][1],cnt+1);
			
			Map[si+dir[i][0]][sj+dir[i][1]]='.';
		}
	}
	return;
}
