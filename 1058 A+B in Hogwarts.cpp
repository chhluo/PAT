#include <iostream>
using namespace std;
struct Currency {
	int g,s,k;
};
Currency a,b,c;
int main() {
	scanf("%d.%d.%d %d.%d.%d",&a.g,&a.s,&a.k,&b.g,&b.s,&b.k);
	c.k = a.k + b.k;
	c.s = a.s + b.s + c.k / 29;
	c.k %= 29;
	c.g = a.g + b.g + c.s / 17;
	c.s %= 17;
	printf("%d.%d.%d",c.g,c.s,c.k);
	return 0;
}
