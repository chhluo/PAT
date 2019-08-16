#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;
int table[128] = {0};
string s1,s2;
int main() {
	cin >> s1 >> s2;
	for(auto it = s2.begin(); it != s2.end(); it ++)
		table[toupper(*it)] ++;
	for(auto it = s1.begin(); it != s1.end(); it ++) {
		if(table[toupper(*it)] == 0) {
			printf("%c",toupper(*it));
			table[toupper(*it)] = -1;
		}
	}
	return 0;
}
