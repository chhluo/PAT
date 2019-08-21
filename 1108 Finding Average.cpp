#include <iostream>
#include <cctype>
#include <string>
#include <cmath>
using namespace std;
int N;
bool judge(string s) {
	int cntnd = 0,cntp = 0,pos1,pos2,len = s.length();
	for(int i = 0; i < len; i ++) {
		if(s[i] == '+' || s[i] == '-') {
			cntnd ++;
			pos2 = i;
		} else if(s[i] == '.') {
			cntp ++;
			if(cntp == 1)
				pos1 = i;
		} else if(s[i] < '0' || s[i] > '9')
			return false;
	}
	if(cntnd > 1)	return false;
	else if(cntnd == 1 && pos2 != 0)	return false;
	else if(cntp == 2)	return false;
	else if(cntp == 1 && len - pos1 > 3)	return false;
	else {
		double v = stod(s);
		return fabs(v) <= 1000;
	}
}

int main() {
	scanf("%d",&N);
	string s;
	int cnt = 0;
	double avg = 0.0;
	for(int i = 0; i < N; i ++) {
		cin >> s;
		if(judge(s)) {
			avg += stod(s);
			cnt ++;
		} else {
			printf("ERROR: %s is not a legal number\n",s.c_str());
		}
	}
	if(cnt == 0)
		printf("The average of 0 numbers is Undefined");
	else if(cnt == 1)
		printf("The average of 1 number is %.2lf",avg);
	else
		printf("The average of %d numbers is %.2lf",cnt,avg / cnt);
	return 0;
}
