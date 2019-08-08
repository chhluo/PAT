#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100010
int N,M, A[MAXN];
int dist[MAXN];
int main() {
	scanf("%d",&N);
	int sum = 0;
	for(int i = 1; i <= N; i ++) {
		scanf("%d", A + i);
		sum += A[i];
		dist[i] = sum;
	}
	scanf("%d",&M);
	int v1,v2,d;
	for(int i = 0; i < M; i ++) {
		scanf("%d%d",&v1,&v2);
		if(v1 == v2)
			d = 0;
		else {
			if(v1 > v2)
				swap(v1,v2);
			if(v1 == 1) {
				d = min(dist[v2-1],sum - dist[v2-1]);
			} else
				d = min(dist[v2 - 1] - dist[v1 -1],sum - (dist[v2 - 1] - dist[v1 -1]));
		}
		printf("%d\n",d);
	}
	return 0;
}


