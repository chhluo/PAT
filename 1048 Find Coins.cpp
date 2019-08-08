#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100010
int N,M;
int cnt[501] = {0};
int A[MAXN];
int main() {
	scanf("%d %d",&N,&M);
	for(int i = 0; i < N; i ++) {
		scanf("%d",A + i);
		cnt[A[i]] ++;
	}
	int v1 = -1,tmp,Minv = 501;
	for(int i = 1; i < N; i ++) {
		cnt[A[i]] --;
		tmp = M - A[i];
		if(tmp >= 0 && tmp <= 500 && cnt[tmp] > 0 && A[i] <= tmp) {
			if(A[i] < Minv)
				Minv = v1 = A[i];
		}
	}
	if(v1 == -1)
		printf("No Solution");
	else
		printf("%d %d",v1,M - v1);
	return 0;
}


