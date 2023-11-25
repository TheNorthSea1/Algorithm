

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn = 1e6 + 5;

int Next[maxn][28];// next[i][j] 表示 i 位置的后头 最近的 j字符 位置的。 

void get_next(string s){
	
	for(int i=s.size()-2;i>=0;i--){
		
		for(int j = 0 ; j<= 26 ;j++){
			Next[i][j] = Next[i+1][j];
		}
		Next[i][ s[i+1] - 'a'] =  i+1;
	}
	
}

int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 	
	ms(Next,0);
	string s;
	cin>>s;
	s="&" + s;
	 
	 get_next(s);
	 
	int m;
	cin>>m;
	while(m--){
		string w;
		cin>>w;
		int f=0;
		int p=0;
		for(int i=0;i<w.size();i++){
			if(Next[p][w[i] - 'a'] == 0){
				f=1;
				break;
			} 
			p = Next[p][ w[i] - 'a'];
			
		}
		
		if(f){
			puts("No");
		}else{
			puts("Yes");
		}
		
	}

}

