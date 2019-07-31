#include <cstdio>
using namespace std;
#define MAXN 10010
int N;
int A[MAXN],dp[MAXN] = {0},idx[MAXN];

void f(int i) {
	if(i == 0) {
		dp[i] = A[i];
		idx[i] = 0;
	} else {
		if(dp[i - 1] < 0) {
			dp[i] = A[i];
			idx[i] = i;
		} else {
			idx[i] = idx[i-1];
			dp[i] = dp[i-1]+A[i];
		}
	}
}

int main() {
	scanf("%d",&N);
	bool flag = false;
	for(int i = 0; i < N; i ++) {
		scanf("%d",A + i);
		if(A[i] >= 0)
			flag = true;
	}
	if(!flag)
		printf("0 %d %d",A[0],A[N-1]);
	else {
		for(int i = 0; i < N; i ++)
			f(i);
		int Max = 0;
		for(int i = 0; i < N; i ++)
			if(dp[i] > dp[Max])
				Max = i;
		printf("%d %d %d",dp[Max],A[idx[Max]],A[Max]);
	}
	return 0;
}
