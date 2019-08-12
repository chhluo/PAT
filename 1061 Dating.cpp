#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string week[8] = {"","MON","TUE","WED","THU","FRI","SAT","SUN"};
int main() {
	string A,B,C,D;
	cin >> A >> B >> C >> D;
	int w,h,m;
	int pos = 0;
	int len1 = A.length(), len2 = B.length();
	while(pos < len1 && pos < len2) {
		if(A[pos] >= 'A' && A[pos] <= 'G' && A[pos] == B[pos]) break;
		else pos ++;
	}
	w = A[pos] - 'A' + 1;
	pos ++;
	while(pos < len1 && pos < len2) {
		if(A[pos] == B[pos] && (isdigit(A[pos]) || (A[pos] <= 'N' && A[pos] >= 'A'))) break;
		else pos ++;
	}
	h = isalpha(A[pos]) ? A[pos] - 'A' + 10 :A[pos] - '0';
	m = 0;
	while(1) {
		if(isalpha(C[m]) && C[m] == D[m]) break;
		else m ++;
	}
	printf("%s %02d:%02d",week[w].c_str(),h,m);
	return 0;
}
