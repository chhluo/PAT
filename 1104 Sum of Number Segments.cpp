#include <iostream>
using namespace std;
#define MAXN 100010
int N;
double A[MAXN],sum = 0.0;
int main() {
	scanf("%d",&N);
	for(int i = 0; i < N; i ++) {
		scanf("%lf",A + i);
		sum += A[i] * (i + 1) * (N - i);
	}
	printf("%.2lf",sum);
	return 0;
}
