#include <bits/stdc++.h>
using namespace std;
vector<int>vec;
vector<int>ans;
int f[20],n,m;//注意题目m的范围 
void rev_kangtuo(int k){
	int n=vec.size(),len=0;
	ans.clear();
	k--;
	for (int i=1;i<=n;i++){
		int t;
		if (n-i>10)t=0;//注意此处当n-i>10的时候，阶乘10就已经很大了。所以此时整除肯定为0. 
		else t=k/f[n-i],k%=f[n-i];
		ans.push_back(vec[t]);
		vec.erase(vec.begin()+t);
	}
}
int main() {
    f[0]=1;
    for (int i=1;i<=10;i++)f[i]=f[i-1]*i;//注意该处为什么只需要到10就行。 
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
