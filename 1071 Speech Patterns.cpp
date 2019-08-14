#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;
#define MAXN 1048580
map <string,int> mp;

int main() {
	string s;
	while(cin >> s) {
		auto i = s.begin();
		while(i != s.end()) {
			while(i != s.end() && !isalnum(*i)) i ++;
			string ss = "";
			for(; i != s.end(); i ++) {
				if(isalnum(*i)) ss.push_back(tolower(*i));
				else break;
			}
			if(ss.length() != 0)
				mp[ss] ++;
		}
	}
	auto Max = mp.begin();
	for(auto it = mp.begin(); it != mp.end(); it ++) {
		if(it->second > Max->second || it->second == Max->second && it->first < Max->first)
			Max = it;
	}
	printf("%s %d",Max->first.c_str(),Max->second);
	return 0;
}
