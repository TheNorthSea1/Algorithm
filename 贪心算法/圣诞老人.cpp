#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const double eps=1e-6;
struct Candy{
	int v;
	int w;
	bool operator<(const Candy&c){
		return double(v)/w-double(c.v)/c.w>eps;
	}
}candies[110];
int main()
{
	int n,w;
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>candies[i].v>>candies[i].w;
	}
	sort(candies,candies+n);
	int totalw=0;
	double totalv=0;
	for(int i=0;i<n;i++){
		if(totalw+candies[i].w<=w){
			totalw+=candies[i].w;
			totalv+=candies[i].v; 
		}else{
			totalv+=candies[i].v*double(w-totalw)/candies[i].w;
			break;
		} 
	}
	printf("%.1f",totalv);
 } 
 
 
 
 
 
 
 
