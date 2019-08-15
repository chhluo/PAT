#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 30
int N,seq[MAXN];
typedef struct Node * AVLTree;
struct Node {
	int d,h;
	AVLTree l,r;
	Node() {};
	Node(int dd):d(dd),h(1),l(NULL),r(NULL) {}
};
int getHeight(AVLTree root) {
	return root ? root->h : 0;
}
int getBalanceFactor(AVLTree root) {
	return getHeight(root->l) - getHeight(root->r);
}
void updateHeight(AVLTree root) {
	root->h =  max(getHeight(root->l),getHeight(root->r)) + 1;
}
void leftRotate(AVLTree & root) {
	AVLTree tmp = root->l;
	root->l = tmp->r;
	tmp->r = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}
void rightRotate(AVLTree & root) {
	AVLTree tmp = root->r;
	root->r = tmp->l;
	tmp->l = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;
}
void insert(AVLTree & root,int d) {
	if(!root) {
		root = new Node(d);
	} else {
		if(root->d > d) {
			insert(root->l,d);
			updateHeight(root);
			if(getBalanceFactor(root) == 2) {
				if(getBalanceFactor(root->l) == -1)
					rightRotate(root->l);
				leftRotate(root);
			}
		} else {
			insert(root->r,d);
			updateHeight(root);
			if(getBalanceFactor(root) == -2) {
				if(getBalanceFactor(root->r) == 1)
					leftRotate(root->r);
				rightRotate(root);
			}
		}
	}
}
int main() {
	scanf("%d",&N);
	AVLTree T = NULL;
	int d;
	for(int i = 0; i < N; i ++) {
		scanf("%d",&d);
		insert(T,d);
	}
	printf("%d",T->d);
	return 0;
}
