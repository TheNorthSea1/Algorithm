#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define inf 0x7FFFFFFF
int N,M;
int map[300][300],final[300]={0},dist[300],pos[300]={0};
int main()
{
	int A,B,X,start,target,next;
	while(cin>>N>>M){
		for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			dist[i]=inf;
			map[i][j]=inf;
			final[i]=0;
		}
		while(M--){
			cin>>A>>B>>X;
			map[A][B]=min(map[A][B],X);
			map[B][A]=map[A][B];
		}
		cin>>start>>target;
		
		final[start]=1;
		dist[start]=0;
		while(start!=target){
			int min=inf;
			for(int i=0;i<N;i++){
				if(map[start][i]!=inf){
					if(map[start][i]+dist[start]<dist[i]){
						   pos[i]=start;
						   dist[i]=map[start][i]+dist[start];                        
					}                
				}                                 
				if(final[i]==0&&dist[i]<min){
					next=i;              
					min=dist[i];       
				}  
				}                                 
				if(min==inf) break;            
				start=next;             
				final[start]=1;     
			
		}
		if(dist[target]==inf) cout<<-1<<endl;
		else cout<<dist[target]<<endl;
	}
	return 0;
 } 
