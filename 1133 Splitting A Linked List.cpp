#include <iostream>
using namespace std;
#define MAXN 100010
int N,K,head;
struct Node {
	int ad,d,next;
};
Node A[MAXN],B[MAXN],tmp;
int main() {
	scanf("%d%d%d",&head,&N,&K);
	for(int i = 0; i < N; i ++) {
		scanf("%d%d%d",&tmp.ad,&tmp.d,&tmp.next);
		A[tmp.ad] = tmp;
	}
	int p = head,cnt = 0;
	while(p != -1) {
		B[cnt ++] = A[p];
		p = A[p].next;
	}
	int k = 0;
	for(int i = 0; i < cnt; i ++)
		if(B[i].d < 0) A[k ++] = B[i];
	for(int i = 0; i < cnt; i ++)
		if(B[i].d <= K && B[i].d >= 0) A[k ++] = B[i];
	for(int i = 0; i < cnt; i ++)
		if(B[i].d > K) A[k ++] = B[i];
	for(int i = 0; i + 1 < cnt; i ++)
		printf("%05d %d %05d\n",A[i].ad,A[i].d,A[i+1].ad);
	printf("%05d %d -1",A[cnt - 1].ad,A[cnt - 1].d);
	return 0;
}
