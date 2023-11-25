/*
PTA  团体程序设计天梯赛;



尽量考虑使用sacnf 

*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define For(N) for(int i=0;i<N;i++) 
int sex[1005];
double Map[1005][1005];
int read(){//读数字 
	string s;
	int flag=0;//0 is girl,1 is boy
	cin>>s;
	if(s[0]=='-'){
		int sum=0;
		for(int i=1;i<s.size();i++){
			sum=sum*10+(s[i]-'0');
		}
		sex[sum]=0;
		return sum;
	}else{
		int sum=0;
		for(int i=0;i<s.size();i++){
			sum=sum*10+(s[i]-'0');
		}
		sex[sum]=1;
		return sum;
	}
}
void print(int a,int b){//输出 
	if(sex[a]==0) {
		cout<<"-"<<a;
	}else{
		cout<<a;
	}
	if(sex[b]==0){
		cout<<" -"<<b<<endl;	
	}else{
		cout<<" "<<b<<endl;
	}
}
int main()
{
	int N,M;
//	cin>>N>>M;
	scanf("%d%d",&N,&M);
	For(M){
		int k;
//		cin>>k;
		scanf("%d",&k);
		vector<int> cp[2];//cp[0] 存女，cp[1]存男 
		For(k){
			int peo=read();
			cp[sex[peo]].push_back(peo);
		}
		for(int i=0;i<cp[0].size();i++)
		for(int j=0;j<cp[1].size();j++){
			Map[cp[0][i]][cp[1][j]]+=1.0/k;
			Map[cp[1][j]][cp[0][i]]+=1.0/k;
		}
	}
	int A=read(),B=read();
	double Amax=0,Bmax=0;
	For(N){                       //求出A，B对应的最高亲密度 
		Amax=max(Amax,Map[A][i]);
		Bmax=max(Bmax,Map[B][i]);
	}
	if(Map[A][B]==Amax&&Amax==Bmax){
		print(A,B);
	}else{
		For(N) if(Map[A][i]==Amax) print(A,i);
		For(N) if(Map[B][i]==Bmax) print(B,i);
	}
//	cout<<sex[0]<<endl; 
 } 
     
       
           
         
          
