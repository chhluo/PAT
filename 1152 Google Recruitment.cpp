#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int N,L;
string s;
bool prime(int n) {
	if(n == 1)	return false;
	else if(n == 2)	return true;
	else {
		int e = sqrt(n);
		for(int i = 2; i <= e; i ++)
			if(n % i == 0)
				return false;
		return true;
	}
}
int main() {
	cin >> N >> L >> s;
	for(int i = 0; i <= N - L; i ++) {
		int x = stoi(s.substr(i,L));
		if(prime(x)) {
			cout << s.substr(i,L);
			return 0;
		}
	}
	cout << "404" << endl;
	return 0;
}
