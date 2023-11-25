#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn = 1e5 + 5;
const int mod = 1e9+7;
int N,K;

ll dp[12][99][100]; // dp[ i ][ j ][ k ] ��ʾ�ӵ�һ�е���i��  j״̬��  ��K������ �������� 

int state[999];//�����Ӧ��״̬ 

int king[999];//ÿ��״̬��Ӧ�Ĺ������� 

int biao;

ll sum; //ע��˴���sum Ҫ�� long long 

void init(){
	int tot= (1<<N) -1;
	for(int i=0;i<=tot;i++){ //��ȡÿ��һ�е�״̬ 
	
		if( i & (i<<1)) continue;  //���ڲ����й���
		
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

	for(int i=0;i<biao;i++){  //Ԥ�����һ�� 
		if(king[i] <= K){
			dp[1][i][ king[i] ] = 1;
		}	
	}
	
	for(int i=2;i<=N;i++){
		for(int j=0;j<biao;j++){  //ö��״̬
		 
			for(int p=0;p<biao;p++){ //ö��״̬ 
				
				int sj = state[j];
				
				int sp = state[p];
				
				if( sj & sp ) continue;  // ���� ���ܷ���ͬһ�� 
				
				if( sj & (sp<<1) ) continue; // ���ܷ������� 
				
				if( sj & (sp>>1) ) continue;//  ���ܷ������� 
				 
				
				for(int s=1;s<=K;s++){  // ״̬ת�� 
					
					if(king[j] + s > K) break;
					
					dp[i][j][ king[j] + s] += dp[i-1][p][ s ];
				}
			}
		}
	} 

	for(int i=1;i<=N;i++){
		for(int j=0;j<biao;j++){
			sum += dp[i][j][K];   //Ѱ�ҷ���K����������� 
		}
	}



	cout<<sum<<endl;

}

