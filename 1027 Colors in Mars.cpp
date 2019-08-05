#include <cstdio>
using namespace std;
int r,g,b;
void process(int n) {
	if(n < 13) {
		printf("0%c",n < 10 ? (n + '0') : ('A' + n - 10));
	} else {
		int tmp = n % 13;
		n /= 13;
		printf("%c", n < 10 ?(n + '0') : ('A' + n - 10));
		printf("%c",tmp < 10 ? (tmp + '0') : ('A' + tmp - 10));
	}
}
int main() {
	scanf("%d%d%d",&r,&g,&b);
	printf("#");
	process(r);
	process(g);
	process(b);
	return 0;
}
