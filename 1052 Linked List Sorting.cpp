#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 1000010
struct Node {
	int ad,d,next;
	bool operator < (Node X)const {
		return this->d < X.d;
	}
};
Node A[MAXN],B[MAXN];
int N,ad;
int main() {
	scanf("%d%d",&N,&ad);
	Node tmp;
	for(int i = 0; i < N; i ++) {
		scanf("%d%d%d",&tmp.ad,&tmp.d,&tmp.next);
		A[tmp.ad] = tmp;
	}
	int k = 0,p = ad,cnt = 0;
	while(p != -1) {
		B[k ++] = A[p];
		p = A[p].next;
		cnt ++;
	}
	sort(B,B + cnt);
	printf("%d ",cnt);
	if(cnt == 0) {
		printf("-1\n");
	} else {
		printf("%05d\n",B[0].ad);
		for(int i = 0; i < cnt - 1; i ++)
			printf("%05d %d %05d\n",B[i].ad,B[i].d,B[i + 1].ad);
		printf("%05d %d -1",B[cnt - 1].ad,B[cnt - 1].d);
	}
	return 0;
}


