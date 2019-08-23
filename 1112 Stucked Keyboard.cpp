#include <iostream>
#include <string>
using namespace std;
int K;
bool good[128] = {false};
bool appear[128] = {false};
int main() {
	scanf("%d",&K);
	string s,ans,mayStuck,Stuck;
	cin >> s;
	int len = s.length();
	for(int i = 0; i < len;) {
		int cnt = 1,pos = i + 1;
		while(pos < len && s[i] == s[pos]) {
			pos ++;
			cnt ++;
		}
		if(cnt % K != 0) {
			good[s[i]] = true;
		} else {
			mayStuck.push_back(s[i]);
		}
		i = pos;
	}
	for(auto it = mayStuck.begin(); it != mayStuck.end(); it ++) {
		if(!good[*it] && !appear[*it]) {
			Stuck.push_back(*it);
			appear[*it] = true;
		}
	}
	for(int i = 0; i < len;) {
		int cnt = 1,pos = i + 1;
		while(pos < len && s[i] == s[pos]) {
			cnt ++;
			pos ++;
		}
		ans += string(good[i] ? cnt : cnt / K,s[i]);
		i = pos;
	}
	cout << Stuck << endl << ans << endl;
	return 0;
}
