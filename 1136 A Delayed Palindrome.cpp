#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAXN 1100

void add(string &X,string &Y,string &Z) {
	int C = 0,i = 0;
	int len = X.length();
	Z.clear();
	while(i < len) {
		int tmp = X[i] - '0' + Y[i] - '0' + C;
		C = tmp / 10;
		Z.push_back(tmp % 10 + '0');
		i ++;
	}
	if(C)	Z.push_back(C + '0');
}
bool palindromic(string & X) {
	int low = 0,high = X.length() - 1;
	while(low < high) {
		if(X[low] != X[high])
			return false;
		else {
			low ++;
			high --;
		}
	}
	return true;
}

int main() {
	string X,Y,Z;
	cin >> X;
	int cnt = 10;
	if(palindromic(X))
		cout << X << " is a palindromic number." << endl;
	else {
		while(cnt --) {
			Y = X;
			reverse(Y.begin(),Y.end());
			add(X,Y,Z);
			reverse(Z.begin(),Z.end());
			cout << X << " + " << Y << " = " << Z << endl;
			if(palindromic(Z)) {
				cout << Z << " is a palindromic number." << endl;
				return 0;
			} else {
				X = Z;
			}
		}
		cout << "Not found in 10 iterations." << endl;
	}
	return 0;
}
