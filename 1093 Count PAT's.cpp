#include <iostream>
#include <string>
using namespace std;
string s1;
int total = 0,cntP = 0,cntT = 0;
int main() {
	cin >> s1;
	for(auto it = s1.begin(); it != s1.end(); it ++)
		cntT += (*it == 'T');
	for(auto it = s1.begin(); it != s1.end(); it ++)
		if(*it == 'P') cntP ++;
		else if(*it == 'A') {
			total += cntP * cntT;
			total %= 1000000007;
		} else cntT --;
	printf("%d",total);
	return 0;
}
