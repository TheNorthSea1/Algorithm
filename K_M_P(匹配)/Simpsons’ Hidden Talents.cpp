//HDU 考察KMP的知识，next数组的含义 


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
const int maxn=5e5+5;
int Next[maxn*3];
void getNext(string b){
    int j=0;
    int len=b.size();
    b="0"+b;
    Next[1]=0;
    for(int i=1;i<len;i++){
        while(j>0&&b[i+1]!=b[j+1]) j=Next[j];
        if(b[i+1]==b[j+1]) j++;
        Next[i+1]=j;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    string a,b;
    while(cin>>a>>b){
        memset(Next,0,sizeof(Next)); 
        int len1=a.size();
        int len2=b.size();
        a+=b;
        getNext(a);
        int index=Next[a.size()];
        while(index>len1||index>len2){
            index=Next[index];
        }
        if(index==0){
            cout<<0<<endl;
        }else{
            cout<<a.substr(0,index)<<" "<<index<<endl;
        }
    }
}


