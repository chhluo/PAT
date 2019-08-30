#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100010
int N,A[MAXN];
int main() {
	scanf("%d",&N);
	for(int i = 0; i < N; i ++)
		scanf("%d",A + i);
	sort(A,A + N);
	int E = N;
	while(E > 0) {
		if(A[N - E] > E) break;
		else E --;
	}
	printf("%d",E);
	return 0;
}
