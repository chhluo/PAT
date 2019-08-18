#include <iostream>
#include <cctype>
#include <string>
using namespace std;
string s1,s2;
int cnt1[128] = {0}, cnt2[128] = {0};
int main() {
	cin >> s1 >> s2;
	for(auto it = s1.begin(); it != s1.end(); it ++)
		cnt1[*it] ++;
	for(auto it = s2.begin(); it != s2.end(); it ++)
		cnt2[*it] ++;
	int ll = 0,mm = 0;
	for(int i = 0; i < 128; i ++)
		if(cnt2[i] > cnt1[i]) ll += (cnt2[i] - cnt1[i]);
		else mm += (cnt1[i] - cnt2[i]);
	printf("%s %d",ll > 0 ? "No":"Yes",ll > 0 ? ll:mm);
	return 0;
}
