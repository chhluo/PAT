#include <iostream>
#include <algorithm>
using namespace std;
int N,A[100010];
int n1,n2,S1,S2 = 0;
int main() {
	scanf("%d",&N);
	for(int i = 0; i < N; i ++) {
		scanf("%d",A + i);
		S2 += A[i];
	}
	sort(A,A + N);
	n1 = N / 2;
	for(int i = 0; i < n1; i ++)
		S1 += A[i];
	S2 -= S1;
	n2 = N - n1;
	printf("%d %d",abs(n1-n2),abs(S2 - S1));
	return 0;
}
