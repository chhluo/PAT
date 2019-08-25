#include <iostream>
#include <cmath>
using namespace std;
#define MAXN 1010
int K,A[MAXN];
bool judge(int A[],int n) {
	for(int i = 1; i < n; i ++) {
		for(int j = i + 1; j <= n; j ++) {
			if(A[i] == A[j] || abs(i-j) == abs(A[i]-A[j]))	return false;
		}
	}
	return true;
}

int main() {
	scanf("%d",&K);
	int n;
	for(int i = 0; i < K; i ++) {
		scanf("%d",&n);
		for(int j = 1; j <= n; j ++)
			scanf("%d",A + j);
		printf("%s\n",judge(A,n) ? "YES":"NO");
	}
	return 0;
};
