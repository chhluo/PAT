#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
int N,M;
set <string> st;
vector <string> al,noal;
bool cmp(const string & x,const string & y) {
	return x.substr(6,7) < y.substr(6,7);
}
int main() {
	scanf("%d",&N);
	char s[20];
	for(int i = 0; i < N; i ++) {
		scanf("%s",s);
		st.insert(s);
	}
	scanf("%d",&M);
	for(int i = 0; i < M; i ++) {
		scanf("%s",s);
		if(st.find(s) != st.end()) {
			al.push_back(s);
		} else
			noal.push_back(s);
	}
	string ans;
	if(al.size() != 0)
		ans = *min_element(al.begin(),al.end(),cmp);
	else
		ans = *min_element(noal.begin(),noal.end(),cmp);
	printf("%d\n%s",al.size(),ans.c_str());
	return 0;
}
