#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
#define MAX 10100
int P,M,N;
struct Student {
	string name;
	int gp,gm,gf,g;
	Student():gp(-1),gm(-1),gf(-1) {}
};
map <string,Student> mp;
vector <Student> ans;
bool cmp(Student &X,Student &Y) {
	if(X.g != Y.g)
		return X.g > Y.g;
	else
		return X.name < Y.name;
}
int main() {
	scanf("%d%d%d",&P,&M,&N);
	char name[25];
	int score;
	for(int i = 0; i < P; i ++) {
		scanf("%s%d",name,&score);
		if(score >= 200) {
			mp[name].gp = score;
			mp[name].name = name;
		}
	}
	for(int i = 0; i < M; i ++) {
		scanf("%s %d",name,&score);
		auto it = mp.find(name);
		if(it != mp.end())
			it->second.gm = score;
	}
	for(int i = 0; i < N; i ++) {
		scanf("%s %d",name,&score);
		auto it = mp.find(name);
		if(it != mp.end()) {
			it->second.gf = score;
			if(it->second.gm > it->second.gf) {
				it->second.g =round(0.4 * it->second.gm + 0.6 * it->second.gf);
			} else
				it->second.g = it->second.gf;
		}
	}
	for(auto it = mp.begin(); it != mp.end(); it ++) {
		if(it->second.g >= 60)
			ans.push_back(it->second);
	}

	sort(ans.begin(),ans.end(),cmp);
	for(auto it = ans.begin(); it != ans.end(); it ++)
		printf("%s %d %d %d %d\n",it->name.c_str(),it->gp,it->gm,it->gf,it->g);
	return 0;
}
