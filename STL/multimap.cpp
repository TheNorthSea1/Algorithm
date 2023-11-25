#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>
#include<cmath>
#include<map>
using namespace std;
struct StudentInfo {
	int id;
	char name[20];
};
struct Student {
	int score;
	StudentInfo info;
};
typedef multimap<int,StudentInfo> MAP_STD;
int main()
{
	MAP_STD mp;
	Student st;
	char cmd[20];
	while(cin>>cmd){
		if(cmd[0]=='A'){
			cin>>st.info.name>>st.info.id>>st.score;
			mp.insert(make_pair(st.score,st.info));
		}else if(cmd[0]=='Q'){
			int score;
			cin>>score;
			MAP_STD::iterator p = mp.lower_bound(score);
			if(p!=mp.begin()){
				p--;
				score=p->first;//��Ҫ��ѯ�����͵���߷� 
				MAP_STD::iterator maxp=p;
				int maxID=p->second.id;
				for(;p!=mp.begin()&&p->first==score;p--){//�������гɼ���score��ȵ�ѧ�� 
					if(p->second.id>maxID){
						maxp=p;
						maxID=p->second.id;
					} 	
				}
				if(p->first==score){//ִ����һ��ԭ���ǿ���p���˽�β����pָ���βʱ��û�к�maxID���бȽϡ� 
					if(p->second.id>maxID){
						maxp=p;
						maxID=p->second.id;
					}
				}
				cout<<maxp->second.name<<" "<<maxp->second.id<<" "<<maxp->first<<endl;
			}else{
				cout<<"Nobody"<<endl;
			}
		}
	}
}
