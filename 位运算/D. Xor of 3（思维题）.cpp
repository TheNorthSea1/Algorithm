/*
https://codeforces.com/contest/1573/problem/D
��Ŀ������
�ȿ��Ǳ任ǰ��Ĳ�����������ÿ�α任������ı����е���ż�ԣ�
Ҫô������ \(1\) Ҫô������ \(1\) ��
����ԭ���������������� \(1\) ���޽⡣


ż���� \(1\) ����£�����һ�������� \(1\) ��
	1.�����ż���� \(1\) �����ڱ������е���ż�����ԣ�һ�����Խ���� \(1\) ȫ��Ϊ \(0\)
	
	2.����������� \(1\) ����ô���ܿ��Լ����꣬����Ҫ����ÿ�ΰ����� \(0\) ��� \(1\) ��
	ֱ������ \(101\) ����������� \(101\) ��� \(000\) ��ǰ��� \(1\) ֻ��ż������
	��ת��Ϊ������������Ϳ���������



�������һ�� \(0��0��0 \cdots 1��1��1\) ����ͺã�����ĩβ�� \(1\) �ĸ�����Ϊż������
����ǰ��ֻҪ���� \(0\) �Ϳ���ȫ�����꣬��ôΨһ�޽������¼�������ת��Ϊ��ȫ \(1\) ���У��� \([1,0,0,1]\) ����

*/


#include<bits/stdc++.h>
#define ms(__x__,__val__) memset(__x__, __val__, sizeof(__x__))
#define FI(__x__,__y__) for(int i=__x__;i<__y__;i++)
#define FJ(__x__,__y__) for(int j=__x__;j<__y__;j++)
#define pb push_back
using namespace std;
int main()
{
 	ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		int cnt=0;
		
		FI(1,n+1) cin>>a[i],cnt+=a[i];
		
		if(cnt&1){  //������� ��1�� �ĸ��������������ǾͲ�����OK 
			cout<<"NO\n";
			continue;
		}
		
		cnt=0;
		vector<int> v;
		for(int i=1;i<=n;i++){
			if(a[i]){
				cnt++;
			}else if(cnt&1){
				
				if(a[i+1]){ // 101
					a[i-1]=a[i+1]=0;
					for(int j=i-1;j>=i-cnt;j-=2){
						v.pb(j),a[j]=a[j+1]=0;	
					}
					cnt=0;
				}else{ //100;
					v.pb(i-1);   //�˴��Ĳ����ͻ��������������� 1 
					a[i]=a[i+1]=1;
					cnt++;
				}
			}else{ //����1�ĸ�����ż���� 
				for(int j=i-2;j>=i-cnt;j-=2){
					v.pb(j),a[j]=a[j+1]=0;
				}
				cnt=0;
			}
		}
	
		if(cnt){
			if(cnt==n){
				cout<<"NO\n";
				continue;
			}else{ //���ĩβ������1 һ��Ϊż��������Ϊ�ܹ�Ϊż����1�����ǰ���1 ������������������л���1 
				for(int j=n-cnt;j<=n-2;j+=2){//���� cnt!= n ���ʾǰ����ż������ 
					v.pb(j);
				}
			}
		}
		cout<<"YES\n";
		cout<<v.size()<<"\n";
		for(int i=0;i<v.size();i++){
			if(i!=0) cout<<" ";
			cout<<v[i];
		}
		if(v.size())	cout<<"\n";	
	
	}
}
