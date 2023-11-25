 #include<iostream>
 #include<algorithm>
 #include<cstring>
 #include<set>
 using namespace std;
 struct Student{
 	char name[20];
 	int id;
 	int score;
 };
 Student students[]={
 	{"Jack",112,78},{"Mary",102,85},{"Ala",333,92},{"zero",101,70},{"Cindy",102,78} 
 };
 struct Rule{
 	bool operator()(const Student &s1,const Student &s2){
 		if(s1.score!=s2.score) return s1.score>s2.score;
 		else return (strcmp(s1.name,s2.name)<0);
	 }
 };
 int main()
 {
 	multiset<Student,Rule> st;
 	for(int i=0;i<5;i++)
 	st.insert(students[i]);
 	multiset<Student,Rule>::iterator p;
 	for(p=st.begin();p!=st.end();p++){
 		cout<<p->score<<" "<<p->name<<" "<<p->id<<endl;
	 }
	Student s={"Mary",1000,85};
	p=st.find(s);
	if(p!=st.end())
		cout<<p->score<<" "<<p->name<<" "<<p->id<<endl;
	return 0;	
 }
