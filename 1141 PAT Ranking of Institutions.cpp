#include <iostream>
#include <cctype>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int N;
struct Institution {
	string school;
	int n,rank,sb,sa,st,tt;
	Institution() {
		sb = sa = st = tt = n = 0;
	}
};
map <string,Institution> mp;
vector <Institution> ans;
bool cmp(Institution & X, Institution & Y) {
	if(X.tt != Y.tt)
		return X.tt > Y.tt;
	else if(X.n != Y.n)
		return X.n < Y.n;
	else
		return X.school < Y.school;
}
string Lowwer(char school[]) {
	string s;
	while(*school) {
		s.push_back(tolower(*school));
		school ++;
	}
	return s;
}

int main() {
	scanf("%d",&N);
	char id[10],school[10];
	int score;
	string s;
	for(int i = 0; i < N; i ++) {
		scanf("%s %d %s",id,&score,school);
		s = Lowwer(school);
		mp[s].n ++;
		mp[s].school = s;
		auto it = mp.find(s);
		if(id[0] == 'A')	it->second.sa += score;
		else if(id[0] == 'B') it->second.sb += score;
		else it->second.st += score;
	}
	for(auto it = mp.begin(); it != mp.end(); it ++) {
		it->second.tt = it->second.sb / 1.5 + it->second.sa + it->second.st * 1.5;
		ans.push_back(it->second);
	}
	sort(ans.begin(),ans.end(),cmp);
	ans.front().rank = 1;
	for(unsigned int i = 1; i < ans.size(); i ++) {
		if(ans[i-1].tt == ans[i].tt)
			ans[i].rank = ans[i-1].rank;
		else
			ans[i].rank = i + 1;
	}
	printf("%d\n",ans.size());
	for(auto it = ans.begin(); it != ans.end(); it ++)
		printf("%d %s %d %d\n",it->rank,it->school.c_str(),it->tt,it->n);
	return 0;
}

