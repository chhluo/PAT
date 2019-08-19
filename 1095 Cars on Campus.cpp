#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;
#define MAXN 10010
int K,N;
typedef enum {IN,OUT} Status;
struct Record {
	string id;
	int t;
	Status stu;
	Record(string ii,int tt,Status ss):id(ii),t(tt),stu(ss) {}
};
typedef Record * PtrToR;
vector <PtrToR> rec;
bool cmp(PtrToR X,PtrToR Y) {
	return X->t < Y->t;
}
map <string,int> ParkTime,lst;
map <string,vector<PtrToR>> mp;
int main() {
	scanf("%d%d",&N,&K);
	char id[10],stu[5];
	int h,m,s,t;
	for(int i = 0; i < N; i ++) {
		scanf("%s %d:%d:%d %s",id,&h,&m,&s,stu);
		PtrToR p = new Record(id,h*3600+m*60+s,stu[0] =='i' ? IN:OUT);
		mp[p->id].push_back(p);
	}
	for(auto it = mp.begin(); it != mp.end(); it ++) {
		sort(it->second.begin(),it->second.end(),cmp);
		vector <PtrToR> tmp;
		for(auto v = it->second.begin(); v != it->second.end(); v ++) {
			if((*v)->stu == IN) {
				if(tmp.size() == 0)
					tmp.push_back(*v);
				else if(tmp.back()->stu == IN) {
					delete tmp.back();
					tmp.pop_back();
					tmp.push_back(*v);
				} else
					tmp.push_back(*v);
			} else {
				if(tmp.size() % 2 == 0)
					delete (*v);
				else
					tmp.push_back(*v);
			}
		}
		if(tmp.size() % 2 == 1)//最后多了1个in 
			tmp.pop_back(); 
		it->second.clear();
		for(auto v = tmp.begin(); v != tmp.end(); v ++)
			rec.push_back(*v);
	}
	sort(rec.begin(),rec.end(),cmp);
	int cnt = 0;
	auto it = rec.begin();
	for(int i = 0; i < K + 1; i ++) {
		if(i < K) {
			scanf("%d:%d:%d",&h,&m,&s);
			t = h * 3600 + m * 60 + s;
		} else
			t = 24 * 3600;
		while(it != rec.end()) {
			if((*it)->t <= t) {
				if((*it)->stu == IN) {
					cnt ++;
					lst[(*it)->id] = (*it)->t;
				} else {
					cnt --;
					ParkTime[(*it)->id] += (*it)->t - lst[(*it)->id];
				}
				it ++;
			} else
				break;
		}
		if(i < K)
			printf("%d\n",cnt);
	}
	vector <string> ans;
	int Max = ParkTime.begin()->second;
	for(auto it = ParkTime.begin(); it != ParkTime.end(); it ++)
		if(it->second > Max) {
			Max = it->second;
			ans.clear();
			ans.push_back(it->first);
		} else if(it->second == Max)
			ans.push_back(it->first);
	sort(ans.begin(),ans.end());
	for(unsigned int i = 0; i < ans.size(); i ++)
		printf("%s ",ans[i].c_str());
	h = Max / 3600;
	m = (Max - h * 3600) / 60;
	s = Max % 60;
	printf("%02d:%02d:%02d",h,m,s);
	return 0;
}
