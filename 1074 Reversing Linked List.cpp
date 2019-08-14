#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100010
int N,K;
struct Node {
	int ad,d,next;
};
Node A[MAXN],B[MAXN];
int main() {
	int ad;
	scanf("%d%d%d",&ad,&N,&K);
	Node tmp;
	for(int i = 0; i < N; i ++) {
		scanf("%d%d%d",&tmp.ad,&tmp.d,&tmp.next);
		A[tmp.ad] = tmp;
	}
	int p = ad,cnt = 0;
	while(p != -1) {
		B[cnt ++] = A[p];
		p = A[p].next;
	}
	for(int i = 0; i + K - 1 < cnt; i += K)
		reverse(B + i,B + i + K);
	for(int i = 0; i < cnt - 1; i ++)
		printf("%05d %d %05d\n",B[i].ad,B[i].d,B[i + 1].ad);
	printf("%05d %d -1\n",B[cnt -1].ad,B[cnt - 1].d);
	return 0;
}

