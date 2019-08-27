#include <iostream>
#include <string>
using namespace std;
string D,s;
int N;
int main() {
	cin >> D >> N;
	for(int i = 0; i < N - 1; i ++) {
		int len = D.length();
		int pos = 0,pre = 0,cnt = 0;
		while(pos < len) {
			pre = pos;
			cnt = 1;
			pos ++;
			for(; pos < len && D[pre] == D[pos]; pos ++,cnt ++);
			s.push_back(D[pre]);
			s.push_back(cnt + '0');
		}
		D = s;
		s.clear();
	}
	cout << D;
	return 0;
}
