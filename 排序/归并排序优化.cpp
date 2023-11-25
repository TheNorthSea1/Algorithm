#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<cstdio>
#define test(a) cout << "-----" << a << "-----" << '\n'
#define ms(__x__,__val__) memset(__x__, __val__, sizeof(__x__))
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 10;

void merge_sort(int *A,int L,int R,int *T){
	if(R==L) return;
	
//			int m=L+R>>1;
		int m=L+(R-L)/2;
	//	int m=(L+R)/2;
		
		int  p=L;
		int  q=m+1;
		int  t=L;
		
		merge_sort(A,L,m,T);
		
		merge_sort(A,m+1,R,T);
		
		while(p<=m||q<=R){
			
			if(q>R || (p<=m && A[p] <= A[q])) T[t++] = A[p++];  //如果q>R 说明 [m+1,R] 的数组已经用完。 
			
			else T[t++] = A[q++];
			
		}
		
		
		for(int i=L;i<=R;i++) A[i] = T[i];
}

int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int A[10]={0,1,5,2,8,77};
	int T[10];
	
	for(int i=1;i<=5;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl<<endl;
	
	merge_sort(A,1,5,T);
	for(int i=1;i<=5;i++){
		cout<<A[i]<<" ";
	}
}

