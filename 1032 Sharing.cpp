#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1000000
struct Node {
	int next;
	char c;
} List[MAXN];
int ListLength(int head) {
	int len = 0,p = head;
	while(p != -1) {
		len ++;
		p = List[p].next;
	}
	return len;
}
int main() {
	int head1,head2,N,ad;
	scanf("%d%d%d",&head1,&head2,&N);
	Node tmp;
	for(int i = 0; i < N; i ++) {
		scanf("%d %c %d",&ad,&tmp.c,&tmp.next);
		List[ad] = tmp;
	}
	int len1 = ListLength(head1), len2 = ListLength(head2);
	if(len1 < len2) {
		swap(head1,head2);
		swap(len1,len2);
	}
	for(; len1 > len2 ; len1 --)
		head1 = List[head1].next;
	//如果一开始就是相同
	if(head1 != -1 && head1 == head2) {
		printf("%05d",head1);
		return 0;
	}
	while (head1 != -1 && List[head1].next != List[head2].next) {
		head1 = List[head1].next;
		head2 = List[head2].next;
	}
	if(head1 == -1 || List[head1].next == -1)
		printf("-1");
	else
		printf("%05d",List[head1].next);
	return 0;
}



