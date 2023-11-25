/*
https://ac.nowcoder.com/acm/problem/25125



��һ��ǰ׺��һ����׺�ͣ�ǰ׺��sum1[i]��¼λ��1...i��a�ĸ�����
��׺��sum2[i]��¼i...n��c�ĸ�������ǰ����ö���ַ���������λ�ã�
�����ǰλ��i���ַ�Ϊ'b'���𰸼���sum1[i-1]*sum2[i+1]���ɣ�ʱ�临�Ӷ�O(n)��

*/

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
const int inf=1e5+5;
int main()
{
	string s;
	cin>>s;
	int a[inf],c[inf];
	memset(a,0,sizeof(a));
	memset(c,0,sizeof(c));
	int cnt=0;
	for(int i=0;i<s.length();i++){//��A����ǰ׺�� 
		if(s[i]=='a'){
			cnt++;
		}
		a[i]=cnt;
	}
	cnt=0;
	for(int i=s.length()-1;i>=0;i--){//��C���к�׺�� 
		if(s[i]=='c'){
			cnt++;
		}
		c[i]=cnt;
	}
	ll ans=0;
	for(int i=0;i<s.length();i++){
		if(s[i]=='b'){
			ans+=a[i-1]*c[i+1]; 
		}
	}
	cout<<ans<<endl;
}

