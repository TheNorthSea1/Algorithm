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
const int maxn=1e5+5;
void swap(int a[],int x,int y);
void HeapAdjust(int a[],int s,int m);
void HeapSort(int a[]);

int ans[11]={0,50,10,90,30,70,40,80,60,20};
int len=9;

  
void HeapAdjust(int a[],int s,int m){  // ������s ~ m �Ĵ���� 
	
	int tmp,j;
	tmp=a[s];
	
	for(j=2*s;j<=m;j*=2){  // j=2*s jΪ s����ڵ� 
		
		if( j+1<=m && a[j]<a[j+1] ){ //j+1 ��Ϊ s �������� ,Ҫ�ж��������Ƿ��� ��Χ�� 
		
			j++;					// �ж� �����ӻ����Һ��� �� 
		}
		
		if( tmp >= a[j] )	break;
		
		
		a[s]=a[j];
		s=j;
		}	
	
	a[s] = tmp;
	
}
	
	 

void HeapSort(int a[]){
	
	int i;
	for(i = len/2 ;i>0 ;i--){
		HeapAdjust(a,i,len);
	}
	
	for( i=len;i>1;i--){
		swap(a[1],a[i]);
//		swap(a,1,i);
		
		HeapAdjust(a,1,i-1); //��i-1 ���� ���½�������� 
	}
	
}

//void swap(int a[],int x,int y){
//	int tmp=a[x];
//	a[x]=a[y];
//	a[y]=tmp;
//}


 
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
// 	HeapAdjust(ans,1,9);
	HeapSort(ans);
	for(int i=1;i<=9;i++){
		cout<<ans[i]<<" ";
	}  
 	
 	
 	
 	
 	
 	

}

