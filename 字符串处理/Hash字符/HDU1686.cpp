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
typedef pair<ll,ll> pll;
const int inf=1e5+5;
const int Mod1=1000000007;
const int Mod2=19260817;
typedef unsigned long long ull;
ull hash1[2][inf],xp[2][inf],hash2[2][inf]; 
void init(){
	xp[0][0]=1,xp[1][0]=1;
	for(int i=1;i<inf;i++){
		xp[0][i]=xp[0][i-1]*13331%Mod1;
		xp[1][i]=xp[1][i-1]*13331%Mod2;
	}
}
void make_hash1(string s){
	ll len=s.length();
	hash1[0][len]=0;
	hash1[1][len]=0;
	for(int i=len-1;i>=0;i--){
		hash1[0][i]=(hash1[0][i+1]*13331%Mod1+s[i]-'A'+1)%Mod1;
		hash1[0][i]=(hash1[0][i+1]*13331%Mod2+s[i]-'A'+1)%Mod2;
	}
}
void make_hash2(string s){
	ll len=s.length();
	hash2[0][len]=0;
	hash2[1][len]=0;
	for(int i=len-1;i>=0;i--){
		hash2[0][i]=(hash2[0][i+1]*13331%Mod1+s[i]-'A'+1)%Mod1;
		hash2[0][i]=(hash2[0][i+1]*13331%Mod2+s[i]-'A'+1)%Mod2;
	}
}
pll Get_hash(int i,int len,ll hash[][]){
	return pll((hash[0][i]-hash[0][i+len]*xp[0][len]%Mod1+Mod1)%Mod1,
			(hash[1][i]-hash[1][i+len]*xp[1][len]%Mod2+Mod2)%Mod2);	
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF){
		while(n--){
			int ans=0;
			string w,T;
			cin>>w>>T;
			make_hash1(w);
			make_hash2(T);
			int lenw=w.length();
			int lent=T.length();
			pll tmp=Get_hash(0,lenw,hash1);
			for(int i=0;i<lent-lenw+1;i++){
				if(Get_hash(i,len2,hash2)==tmp)
				ans++;
			}
			cout<<ans<<endl;
		}
	}
}

