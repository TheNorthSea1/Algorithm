#include<iostream>
#include<set>
#include<map>
#include<cstring>
using namespace std;
struct Word{
	int times;
	string wd;
};
struct Rule{
	bool operator()(const Word &w1,const Word &w2)const{
		if(w1.times!=w2.times)
		return w1.times>w2.times;
		else
		return w1.wd<w2.wd;
	}
};
int main()
{
	string s;
	set<Word,Rule> st;
	map<string,int> mp;
	while(cin>>s)
		mp[s]++;
	map<string,int>::iterator i;	
	for(i=mp.begin();i!=mp.end();i++){
		Word tmp;
		tmp.wd=i->first;
		tmp.times=i->second;
		st.insert(tmp);
	}
	set<Word,Rule>::iterator p;
	for(p=st.begin();p!=st.end();i++){
		cout<<p->wd<<" "<<p->times<<endl; 
	}	
}
 
