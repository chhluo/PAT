#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N;
string s,suf;

int main() {
	scanf("%d\n",&N);
	for(int i = 1; i <= N; i ++) {
		getline(cin,s);
		reverse(s.begin(),s.end());
		if(i == 1) 	suf = s;
		else {
			int len1 = s.length(), len2 = suf.length(),len = 0;
			while(len < len1 && len < len2 && s[len] == suf[len])
				len ++;
			suf = suf.substr(0,len);
		}
	}
	reverse(suf.begin(),suf.end());
	if(suf.length() != 0)
		cout << suf << endl;
	else
		cout << "nai" << endl;
	return 0;
}
