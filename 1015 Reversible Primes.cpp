#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
char str[50];
int N,D;

bool Prime(int n) {
	if(n == 1)
		return false;
	if(n == 2)
		return true;
	for(int i = (int ) sqrt(n); i >= 2; i --)
		if(n % i == 0)
			return false;
	return true;
}
void itostr(int N,char s[],int radix) {
	int i = 0;
	while(N) {
		s[i ++] = (N % radix) + '0';
		N /= radix;
	}
	s[i] = '\0';
	reverse(s,s + i);
}

int stoi(char str[],int radix) {
	int n = 0, len = strlen(str);
	int power = 1;
	for(int i = 0; i < len; i ++) {
		n += (str[i] - '0') * power;
		power *= radix;
	}
	return n;
}

int main() {
	while(1) {
		scanf("%d",&N);
		if(N < 0)
			break;
		scanf("%d",&D);
		if(!Prime(N))
			printf("No\n");
		else {
			itostr(N,str,D);
			N = stoi(str,D);
			printf("%s\n",Prime(N) ? "Yes":"No");
		}
	}
	return 0;
}
