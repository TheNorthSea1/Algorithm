//https://codeforces.com/contest/1572/problem/A  
#include<bits/stdc++.h>
#define test(a) cout << "-----" << a << "-----" << '\n'
#define ms(__x__,__val__) memset(__x__, __val__, sizeof(__x__))
#define Fi(__x__,__y__) for(int i=__x__;i<__y__;i++)
#define Fj(__x__,__y__) for(int j=__x__;j<__y__;j++)
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxn = 1e5 + 5;
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> G[n+1];
		set<int> p,q;
		int in[n+1]; //记入入度每个点的入度 
		ms(in,0);
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			Fj(0,x){
				int w;
				cin>>w;
				G[w].push_back(i);
				in[i]++;
			}
		}
		
		Fi(1,n+1){
			if(!in[i]) 
				q.insert(i);
		} 
		int ans=0;
		vector<int> arr;
		while(!q.empty()){
			ans++;
			for(auto t:q){
				arr.push_back(t);
				for(int i=0;i<G[t].size();i++){
					in[G[t][i]]--;
					if(!in[G[t][i]]){
						if(G[t][i]<t){
							p.insert(G[t][i]);//如果小于，那么只能第二次去阅读了 
						}else{
							q.insert(G[t][i]);//因为可能有的节点虽然暂时度不为0，但是在翻书的时候就为0了 
											 //在该次阅读,可能下面的阅读中会用到。 
						}
					}
				}
			}
			q=p;
			p.clear();
		}
		if(arr.size()==n){
			cout<<ans<<"\n";
		}else{
			cout<<"-1"<<"\n";
		}
		
		
		
		
		
		
		
	} 
																		
									
													
											
								
										

}

