#include <bits/stdc++.h>
using namespace std;
vector<int>vec;
vector<int>ans;
int f[20],n,m;//ע����Ŀm�ķ�Χ 
void rev_kangtuo(int k){
	int n=vec.size(),len=0;
	ans.clear();
	k--;
	for (int i=1;i<=n;i++){
		int t;
		if (n-i>10)t=0;//ע��˴���n-i>10��ʱ�򣬽׳�10���Ѿ��ܴ��ˡ����Դ�ʱ�����϶�Ϊ0. 
		else t=k/f[n-i],k%=f[n-i];
		ans.push_back(vec[t]);
		vec.erase(vec.begin()+t);
	}
}
int main() {
    f[0]=1;
    for (int i=1;i<=10;i++)f[i]=f[i-1]*i;//ע��ô�Ϊʲôֻ��Ҫ��10���С� 
    while (~scanf("%d%d",&n,&m)){
    	for (int i=1;i<=n;i++)vec.push_back(i);
    	rev_kangtuo(m);
    	for (int i=0;i<ans.size();i++){
    		if (i==ans.size()-1)printf("%d\n",ans[i]);
    		else printf("%d ",ans[i]);
    	}                                                            
    }                                                            
    return 0;
}
