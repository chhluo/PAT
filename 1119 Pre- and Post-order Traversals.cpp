#include <iostream>
using namespace std;
#define MAXN 50
int N,pre[MAXN],post[MAXN];
typedef struct Node * BTree;
struct Node {
	int data;
	BTree left,right;
	Node(int dd):data(dd),left(NULL),right(NULL) {}
};
bool flag = true;
void buildTree(BTree & root,int xs,int xe,int hs,int he) {
	if(xs < xe) {
		root = new Node(pre[xs]);
		if(xe - xs == 2)
			flag = false;
		if(xs + 1 < xe) {
			int pos = hs;
			while(pos < he - 1) {
				if(pre[xs + 1] == post[pos])	break;
				else	pos ++;
			}
			int pre_s1,pre_s2,pre_t1,pre_t2;
			int post_s1,post_s2,post_t1,post_t2;
			pre_s1 = xs + 1;
			post_s1 = hs;
			post_t1 = post_s2 = pos + 1;
			post_t2 = he - 1;
			pre_t1 = pre_s2 = pre_s1 + post_t1 - post_s1;
			pre_t2 = xe;
			buildTree(root->left,pre_s1,pre_t1,post_s1,post_t1);
			buildTree(root->right,pre_s2,pre_t2,post_s2,post_t2);
		}
	}
}
int cnt;
void InOrder(BTree root) {
	if(root) {
		InOrder(root->left);
		printf("%d%c",root->data,-- cnt > 0 ? ' ':'\n');
		InOrder(root->right);
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	scanf("%d",&N);
	for(int i = 0; i < N; i ++)
		scanf("%d",pre + i);
	for(int i = 0; i < N; i ++)
		scanf("%d",post + i);
	BTree T = NULL;
	buildTree(T,0,N,0,N);
	printf("%s\n",flag ? "Yes":"No");
	cnt = N;
	InOrder(T);
	return 0;
}
