#include <iostream>
#include <cctype>
#include <string>
using namespace std;
int N;
string ge[13] = {"tret","jan", "feb", "mar", "apr", "may", "jun",
                 "jly", "aug", "sep", "oct", "nov", "dec"
                };
string shi[13] = {" ","tam", "hel", "maa", "huh", "tou", "kes",
                  "hei", "elo", "syy", "lok", "mer", "jou"
                 };

void Mar2Earth(string s) {
	int v = 0;
	if(s.length() > 4) {
		string d = s.substr(0,3);
		for(int i = 0; i < 13; i ++)
			if(shi[i] == d) {
				v = i * 13;
				break;
			}
		string g = s.substr(4);
		for(int i = 0; i < 13; i ++)
			if(g == ge[i]) {
				v += i;
				break;
			}
	} else {
		for(int i = 0; i < 13; i ++)
			if(shi[i] == s) {
				v = i * 13;
				break;
			}
		if(v == 0) {
			for(int i = 0; i < 13; i ++)
				if(ge[i] == s) {
					v = i;
				}
		}
	}
	printf("%d\n",v);
}

void Earth2Mar(int v) {
	string s;
	if(v < 13) {
		s = ge[v];
	} else {
		int d = v / 13,g = v % 13;
		s = shi[d];
		if(g != 0) {
			s.push_back(' ');
			s += ge[g];
		}
	}
	printf("%s\n",s.c_str());
}
int main() {
	scanf("%d\n",&N);
	string s;
	int v;
	for(int i = 0; i < N; i ++) {
		getline(cin,s);
		if(isdigit(s[0])) {
			v = stoi(s);
			Earth2Mar(v);
		} else {
			Mar2Earth(s);
		}
	}
	return 0;
}

