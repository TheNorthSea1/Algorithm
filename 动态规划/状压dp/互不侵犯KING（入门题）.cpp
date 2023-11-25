#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn = 1e5 + 5;
const int mod = 1e9+7;
int N,K;

ll dp[12][99][100]; // dp[ i ][ j ][ k ] 表示从第一行到第i行  j状态下  放K个国王 的种数。 

int state[999];//保存对应的状态 

int king[999];//每种状态对应的国王数量 

int biao;

ll sum; //注意此处的sum 要用 long long 

void init(){
	int tot= (1<<N) -1;
	for(int i=0;i<=tot;i++){ //获取每种一行的状态 
	
		if( i & (i<<1)) continue;  //相邻不能有国王
		
		int w=i;
		int cnt=0;
		state[biao] = i;
		while(w){
			cnt += (w&1);
			w>>=1;
		} 
		king[biao] = cnt;
		biao++; 
	}
} 




int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

 	cin>>N>>K;
 	init();

	for(int i=0;i<biao;i++){  //预处理第一行 
		if(king[i] <= K){
			dp[1][i][ king[i] ] = 1;
		}	
	}
	
	for(int i=2;i<=N;i++){
		for(int j=0;j<biao;j++){  //枚举状态
		 
			for(int p=0;p<biao;p++){ //枚举状态 
				
				int sj = state[j];
				
				int sp = state[p];
				
				if( sj & sp ) continue;  // 相邻 不能放在同一列 
				
				if( sj & (sp<<1) ) continue; // 不能放在左下 
				
				if( sj & (sp>>1) ) continue;//  不能放在右下 
				 
				
				for(int s=1;s<=K;s++){  // 状态转移 
					
					if(king[j] + s > K) break;
					
					dp[i][j][ king[j] + s] += dp[i-1][p][ s ];
				}
			}
		}
	} 

	for(int i=1;i<=N;i++){
		for(int j=0;j<biao;j++){
			sum += dp[i][j][K];   //寻找放满K个国王的情况 
		}
	}



	cout<<sum<<endl;

}

