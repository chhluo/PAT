#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int rate[24],N;
struct Record {
	int M,d,h,m,t;
	bool flag;
	Record() {}
	Record(int MM,int dd,int hh,int mm,int tt,bool ff):M(MM),d(dd),h(hh),m(mm),t(tt),flag(ff) {}
};
typedef map<string,vector <Record>> MP;
MP mp;
bool cmp(Record &x,Record &y) {
	return x.t < y.t;
}
void Duration(Record X,Record Y,int &tt,int &fee) {
	int table[24];
	fill(table,table + 24,0);
	tt = fee = 0;
	if(X.m > 0) {
		table[X.h] -= X.m;
		X.m = 0;
	}
	if(Y.m > 0) {
		table[Y.h] += Y.m;
		Y.m = 0;
	}
	while(X.h < Y.h) {
		table[X.h] += 60;
		X.h ++;
	}
	while(Y.h < X.h) {
		table[Y.h] -= 60;
		Y.h ++;
	}
	while(X.d < Y.d) {
		for(int i = 0; i < 24; i ++)
			table[i] += 60;
		X.d ++;
	}
	for(int i = 0; i < 24; i ++) {
		tt += table[i];
		fee += rate[i] * table[i];
	}
}
int main() {
	freopen("in.txt","r",stdin);
	for(int i = 0; i < 24; i ++)
		scanf("%d",rate + i);
	scanf("%d",&N);
	char name[25], status[10];
	int M,d,h,m,t;
	for(int i = 0; i < N; i ++) {
		scanf("%s %d:%d:%d:%d %s",name,&M,&d,&h,&m,status);
		t = (d * 24 + h) * 60 + m;
		mp[name].push_back(Record(M,d,h,m,t,status[1] == 'n'));
	}
	for(auto it = mp.begin(); it != mp.end(); it ++) {
		sort(it->second.begin(),it->second.end(),cmp);
		vector <Record> tmp;
		unsigned int i = 0;
		while(i < it->second.size()) {
			if(tmp.size() % 2 == 0 && it->second[i].flag) {
				tmp.push_back(it->second[i]);
			} else if(tmp.size() % 2 == 1) {
				if(!it->second[i].flag)
					tmp.push_back(it->second[i]);
				else {
					tmp.pop_back();
					tmp.push_back(it->second[i]);
				}
			}
			i ++;
		}
		if(tmp.size() % 2 == 1) tmp.pop_back();
		it->second = tmp;
	}
	for(auto it = mp.begin(); it != mp.end(); it ++) {
		if(it->second.size() != 0) {
			int total = 0,fee,tt;
			printf("%s %02d\n",it->first.c_str(),it->second.front().M);
			for(unsigned int i = 0; i < it->second.size(); i += 2) {
				Record x = it->second[i],y = it->second[i+1];
				Duration(x,y,tt,fee);
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n",x.d,x.h,x.m,y.d,y.h,y.m,tt,1.0 * fee / 100);
				total += fee;
			}
			printf("Total amount: $%.2lf\n",1.0 * total / 100);
		}
	}
	return 0;
}
