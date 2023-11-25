#include<bits/stdc++.h>
using namespace std;
#define ms(__x__,__val__) memset(__x__, __val__, sizeof(__x__))
#define FI(__x__,__y__) for(int i=__x__;i<__y__;i++)
#define _FI(__x__,__y__) for(int i=__x__;i >= __y__ ;i--)
#define FJ(__x__,__y__) for(int j=__x__;j<__y__;j++)
#define all(_x_) _x_.begin(),_x_.end()
#define pb(__x__) push_back(__x__)
#define IOS ios::sync_with_stdio(0);cin.tie(0); cout.tie(0)
#define debug(__x__,__y__) cout<<__x__<<": "<<__y__<<endl

// #define int ll
typedef long long ll;

const int maxn = 1e5 + 5;
#define inf 0x3f3f3f3f

int bin[205];

int main()
{
 	IOS;
    int _;

	cin>>_;

    while(_--){
        int n;
        cin>>n;
        ms(bin,0);
        FI(0,n){
            int x ,y,a,b;
            cin>>x>>y;
            
            a = min(x,y);
            b = max(x,y);
			
            if(a&1) a++;
            if(b&1) b++;
			
						a/=2;
						b/=2;
			
            FJ(a,b+1) bin[j]++; 
        }

        
        cout<<*max_element(bin,bin+204) * 10<<endl;
	}
    

  
}
