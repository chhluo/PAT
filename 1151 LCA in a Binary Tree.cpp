#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 10010
typedef struct Node *BTree;
struct Node {
	int key;
	BTree left,right;
	Node(int kk):key(kk),left(NULL),right(NULL) {}
};
int N,M,U,V,preSeq[MAXN],inSeq[MAXN];
void buildTree(BTree &root,int pre_s,int pre_t,int in_s,int in_t) {
	if(pre_s < pre_t) {
		root = new Node(preSeq[pre_s]);
		int mid = in_s;
		while(mid < in_t && inSeq[mid] != preSeq[pre_s]) mid ++;
		int n = mid - in_s;
		buildTree(root->left,pre_s + 1,pre_s + 1 + n,in_s,mid);
		buildTree(root->right,pre_s + 1 + n,pre_t,mid + 1,in_t);
	}
}
BTree lca(BTree r,BTree &pu,BTree &pv) {
	if(r) {
		BTree anc = r->key == U || r->key == V ? r : NULL;
		if(r->key == U)	pu = r;
		if(r->key == V)	pv = r;
		BTree pl = lca(r->left,pu,pv);
		anc = anc ? anc : pl;
		BTree pr = lca(r->right,pu,pv);
		anc = anc ? (pr ? r : anc) : pr;
		return anc;
	} else
		return NULL;
}
int main() {
	scanf("%d%d",&M,&N);
	for(int i = 0; i < N; i ++)
		scanf("%d",inSeq + i);
	for(int i = 0; i < N; i ++)
		scanf("%d",preSeq + i);
	BTree T = NULL;
	buildTree(T,0,N,0,N);
	for(int i = 0; i < M; i ++) {
		scanf("%d%d",&U,&V);
		BTree anc = NULL, pu = NULL,pv = NULL;
		anc = lca(T,pu,pv);
		if(!pu && !pv)
			printf("ERROR: %d and %d are not found.\n",U,V);
		else if(!pu)
			printf("ERROR: %d is not found.\n",U);
		else if(!pv)
			printf("ERROR: %d is not found.\n",V);
		else if(anc->key == U || anc->key == V)
			printf("%d is an ancestor of %d.\n",(anc->key == U? U : V),(anc->key == U? V : U));
		else
			printf("LCA of %d and %d is %d.\n",U,V,anc->key);
	}
	return 0;
}
