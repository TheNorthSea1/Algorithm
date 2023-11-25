/*
»¹Î´Í¨¹ý¡£ 

*/
#include<iostream>
#include<queue>
using namespace std;
int s,n,m,vis[100][100][100]={0};
struct cup{
	int A;
	int B;
	int C;
	int steps;
};
int BFS(){
	if(s%2!=0) return -1;
	int result=s/2;
	cup cur,nex;
	cur.A=s;
	cur.B=0;
	cur.C=0;
	cur.steps=0;
	vis[s][0][0]=1;
	queue<cup> q;
	q.push(cur);
	while(!q.empty()){
		cur=q.front();
		q.pop();
		if(cur.A==cur.B&&cur.A==result||cur.A==cur.C&&cur.A==result||
		cur.B==cur.C&&cur.B==result) return cur.steps;
		
		nex.steps=cur.steps+1;
		
		//A->B;
		if(cur.A>=n-cur.B&&cur.B<=n){
			nex.A=cur.A-(n-cur.B);
			nex.B=n;
			nex.C=cur.C;
		}else{
			nex.A=0;
			nex.B=cur.B+cur.A;
			nex.C=cur.C;
		}
		if(vis[nex.A][nex.B][nex.C]==0){
			vis[nex.A][nex.B][nex.C]=1;
			q.push(nex);
		}
		//A->C
		if(cur.A>=m-cur.C&&cur.C<=m){
			nex.A=cur.A-(m-cur.C);
			nex.B=cur.B;
			nex.C=m;
		}else{
			nex.A=0;
			nex.B=cur.B;
			nex.C=cur.C+cur.A;
		}
		if(vis[nex.A][nex.B][nex.C]==0){
			vis[nex.A][nex.B][nex.C]=1;
			q.push(nex);
		}
		//B->A
		if(cur.B>=s-cur.A&&cur.A<=s){
			nex.A=s;
			nex.B=cur.B-(s-cur.A);
			nex.C=cur.C;
		}else{
			nex.A=cur.A+cur.B;
			nex.B=0;
			nex.C=cur.C;
		}
		if(vis[nex.A][nex.B][nex.C]==0){
			vis[nex.A][nex.B][nex.C]=1;
			q.push(nex);
		}
		//B->C
		if(cur.B>=m-cur.C&&cur.C<=m){
			nex.A=cur.A;
			nex.B=cur.B-(m-cur.C);
			nex.C=m;
		}else{
			nex.A=cur.A;
			nex.B=0;
			nex.C=cur.C+cur.B;
		}
		if(vis[nex.A][nex.B][nex.C]==0){
			vis[nex.A][nex.B][nex.C]=1;
			q.push(nex);
		}
		//C->A
		if(cur.C>=s-cur.A&&cur.A<=s){
			nex.A=s;
			nex.B=cur.B;
			nex.C=cur.C-(s-cur.A);
		}else{
			nex.A=cur.A+cur.C;
			nex.B=cur.B;
			nex.C=0;
		}
		if(vis[nex.A][nex.B][nex.C]==0){
			vis[nex.A][nex.B][nex.C]=1;
			q.push(nex);
		}
		//C->B
		if(cur.C>=n-cur.B&&cur.B<=n){
			nex.A=cur.A;
			nex.B=n;
			nex.C=cur.C-(n-cur.B);
		}else{
			nex.A=cur.A;
			nex.B=cur.B+cur.C;
			nex.C=0;
		}
		if(vis[nex.A][nex.B][nex.C]==0){
			vis[nex.A][nex.B][nex.C]=1;
			q.push(nex);
		}
	}
	return -1;
}
int main()
{
	while(cin>>s>>n>>m){
		if(s==0&&n==0&&m==0) break;
		int res=BFS();
		if(res==-1){
			cout<<"NO"<<endl;
		}else{
			cout<<res<<endl;
		}
	}
}
