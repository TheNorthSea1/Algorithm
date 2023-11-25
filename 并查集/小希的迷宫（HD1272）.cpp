#include<iostream>
using namespace std;
int bin[100005],vis[100005];
int flag;
int find(int root){
	int a=root;
	while(a!=bin[a]){
		a=bin[a];
	}
	return a;
}
void merge(int x,int y){
	int a,b;
	a=find(x);
	b=find(y);
	if(a!=b){
		bin[b]=a;
	}else{
		flag=1;
	}
}
int main()
{
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		flag=0;
		if(a==-1&&b==-1) break;
		if(a==0&&b==0){
			cout<<"Yes"<<endl;
			continue;
		}
		for(int i=0;i<100005;i++){
			bin[i]=i;
			vis[i]=0;
		}
		merge(a,b);
		vis[a]=1;
		vis[b]=1;
		
		int x,y;
		while(scanf("%d%d",&x,&y)&&x&&y){
			vis[x]=1;
			vis[y]=1;
			merge(x,y);
		}
		if(flag==1){
			cout<<"No"<<endl;
			continue;
		}else{
			int cnt=0;
			for(int i=0;i<100005;i++){
				if(vis[i]==1&&bin[i]==i){
					cnt++;
				}
			}
			if(cnt==1){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
		}
	}
}
