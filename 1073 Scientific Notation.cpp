#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
char s[12000],tmp[12000];
int main() {
	scanf("%s",s);
	int len = strlen(s);
	int epos = find(s,s + len,'E') - s;
	int e = atoi(s + epos + 1);
	if(s[0] == '-')
		printf("-");
	s[2] = s[1];
	e ++;
	if(e <= 0) {
		printf("0.");
		for(int i = e; i < 0; i ++)
			printf("0");
		s[epos] = 0;
		printf("%s",s + 2);
	} else {
		int n = epos - 2;
		while(n < e) {
			s[n + 2] = '0';
			n ++;
		}
		s[n + 2] = 0;
		int pos = 2;
		while(e > 0) {
			printf("%c",s[pos]);
			pos ++;
			e --;
		}
		if(pos < n + 2) {
			printf(".%s",s + pos);
		}
	}
	return 0;
}
