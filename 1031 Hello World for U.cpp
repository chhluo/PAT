#include <cstdio>
#include <cstring>
using namespace std;
char s[100];

int main() {
	scanf("%s",s);
	int n1,n2,len = strlen(s);

	if((len + 2) % 3 == 0 )
		n1 = n2 = (len + 2) / 3;
	else if((len + 2) % 3 == 1) {
		n1 = (len + 2) / 3;
		n2 = n1 + 1;
	} else {
		n1 = (len + 2) / 3;
		n2 = n1 + 2;
	}
	n1 --;
	for(int i = 0; i < n1; i ++) {
		putchar(s[i]);
		for(int j = 0; j < n2 - 2; j ++)
			putchar(' ');
		putchar(s[len - i - 1]);
		putchar('\n');
	}
	s[n1 + n2] = 0;
	printf("%s",s + n1);

	return 0;
}
