/*
HDU 5037



*/


#include <iostream>
#include <algorithm>
#include <cstdio>
#include<string.h>
using namespace std;

int inf = 200005;
int r[200005];
int main()
{
    int n,m,l,w;
    int i,j;
	int c=1;
	int T;
    scanf("%d",&T);
    while(T>0)
    {
    	memset(r,0,sizeof(r));
		scanf("%d",&n);
		scanf("%d",&m);
		scanf("%d",&l);
        for(i=1;i<=n;++i){
        	scanf("%d",&r[i]);
		}
        sort(r,r+n+1);
        r[1+n] = m;
        
        int sum=0;
		int d=l;
		int cishu,yushu;
		
        for(i=0;i<=n;++i)
        {
            cishu=(r[i+1]-r[i])/(1+l);
            yushu=(r[i+1]-r[i])%(1+l);
            if(yushu+d>l)
            {
                sum+=2*cishu+1;
                d=yushu;
            }
            else
            {
                sum+=2*cishu;
                d+=yushu;
            }
        }
        printf("Case #%d: %d\n",c++,sum);
        T--;
    }


    return 0;
}
