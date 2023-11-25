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
typedef unsigned long long ull;
const int inf=1e6+5;
const int mod=133397;
int len1,len2;
ull hash1[inf],xp[inf],hash2[inf];
void init(){
	xp[0]=1;
	for(int i=1;i<inf;i++)
		xp[i]=xp[i-1]*13331;
	return;	
}
void make_hash(char s[],ull hash[]){
	int len=strlen(s);
	hash[len]=0;
	for(int i=len-1;i>=0;i--){
		hash[i]=hash[i+1]*13331+(s[i]-'A'+1)%mod;
	}
}
ull get_hash(int i,int len,ull hash[]){
	return  (((hash[i]-hash[i+len]*xp[len])%mod)+mod)%mod;
}
int main()
{
		int n;init();
		while(scanf("%d",&n)!=EOF){
			while(n--){
				int ans=0;
				char w[inf],t[inf];
				scanf("%s%s",w,t);
				len1=strlen(w);
				 len2=strlen(t);
				make_hash(w,hash1);
				make_hash(t,hash2);
				ull tmp=get_hash(0,len1,hash1);
//				cout<<tmp<<endl;
				for(int i=0;i<len2-len1+1;i++){
					if(get_hash(i,len1,hash2)==tmp)
					ans++;
				}
				cout<<ans<<endl;
			}
		}
}

