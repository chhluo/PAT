#include <cstdio>
using namespace std;
#define MAXN 40
int N;
typedef struct Node * BTree;
struct Node {
	int data;
	BTree left,right;
	Node() {}
	Node(int d):data(d),left(NULL),right(NULL) {}
};
int postseq[MAXN],inseq[MAXN];

void BuildTree(BTree & T,int ps,int pe,int is,int ie) {
	if(is < ie) {
		T = new Node(postseq[pe - 1]);
		int mid;
		for(int i = is; i < ie; i ++) {
			if(inseq[i] == postseq[pe - 1]) {
				mid = i;
				break;
			}
		}
		BuildTree(T->left,ps,ps + (mid - is),is,mid);
		BuildTree(T->right,ps + (mid - is),pe - 1,mid + 1,ie);
	}
}

void levelTravese(BTree T) {
	BTree Q[MAXN];
	int head = 0,rear = 0;
	Q[rear ++] = T;
	while (head < rear) {
		BTree p = Q[head ++];
		printf("%d%c",p->data,-- N != 0 ? ' ':'\n');
		if(p->left)
			Q[rear ++] = p->left;
		if(p->right)
			Q[rear ++] = p->right;
	}
}
int main() {
	scanf("%d",&N);
	for(int i = 0; i < N; i ++)
		scanf("%d",postseq + i);
	for(int i = 0; i < N; i ++)
		scanf("%d",inseq + i);
	BTree T = NULL;
	BuildTree(T,0,N,0,N);
	levelTravese(T);
	return 0;
}
