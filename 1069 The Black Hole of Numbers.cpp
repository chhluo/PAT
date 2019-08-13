#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

string intTostr(int n) {
	string s = "";
	while(n > 0) {
		s.push_back('0' + n % 10);
		n /= 10;
	}
	while(s.length() < 4)
		s.push_back('0');
	return s;
}

int main() {
	int n;
	cin >> n;
	string smax,smin,s;
	while(1) {
		s = intTostr(n);
		sort(s.begin(),s.end(),greater<char>());
		smax = s;
		sort(s.begin(),s.end());
		smin = s;
		n = stoi(smax) - stoi(smin);
		printf("%s - %s = %04d\n",smax.c_str(),smin.c_str(),n);
		if(n == 0 || n == 6174)		break;
	}
	return 0;
}
