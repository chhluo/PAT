#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
string ans;
vector <string> v;
bool cmp(string s1,string s2) {
	string v1,v2;
	v1 = s1 + s2;
	v2 = s2 + s1;
	return v1 < v2;
}
int main() {
	scanf("%d",&N);
	char s[10];
	for(int i = 0; i < N; i ++) {
		scanf("%s",s);
		v.push_back(s);
	}
	sort(v.begin(),v.end(),cmp);
	for(auto it = v.begin(); it != v.end(); it ++)
		ans += (*it);
	int len = ans.size(),pos = 0;
	while(pos < len && ans[pos] == '0')
		pos ++;
	if(pos == len) printf("0");
	else printf("%s",ans.c_str() + pos);
	return 0;
}
