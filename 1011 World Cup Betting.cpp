#include <cstdio>
#include <algorithm>
using namespace std;
char bets[4] = "WTL";
double odds[3][3],profit = 0.0;
int main() {
	for(int i = 0; i < 3; i ++) {
		for(int j = 0; j < 3; j ++)
			scanf("%lf",&odds[i][j]);
	}
	int g1,g2,g3;
	g1 = max_element(odds[0],odds[0] + 3) - odds[0];
	g2 = max_element(odds[1],odds[1] + 3) - odds[1];
	g3 = max_element(odds[2],odds[2] + 3) - odds[2];
	profit = (odds[0][g1] * odds[1][g2] * odds[2][g3] * 0.65 - 1)* 2;
	printf("%c %c %c %.2lf",bets[g1],bets[g2],bets[g3],profit);
	return 0;
}
