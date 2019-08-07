#include <iostream>
using namespace std;
#define MAXN 10010
int N;
int table[MAXN] = {0},A[100010];
int main() {
	scanf("%d",&N);
	for(int i = 0; i < N; i ++) {
		scanf("%d", A + i);
		table[A[i]] ++;
	}
	int win = -1;
	for(int i = 0; i < N; i ++)
		if(table[A[i]] == 1) {
			win = A[i];
			break;
		}
	if(win != -1)
		printf("%d",win);
	else
		printf("None");
	return 0;
}
