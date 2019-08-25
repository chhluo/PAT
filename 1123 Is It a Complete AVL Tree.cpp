#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N;
typedef struct BNode *BTree;
struct BNode {
	int key,height;
	BTree left,right;
	BNode(int kk):key(kk),height(1),left(NULL),right(NULL) {}
};
int GetHeight(BTree root) {
	return root ? root->height : 0;
}
void UpdateHeight(BTree root) {
	root->height = max(GetHeight(root->left),GetHeight(root->right)) + 1;
}
int GetBF(BTree root) {
	return GetHeight(root->left) - GetHeight(root->right);
}
void LRotate(BTree &root) {
	BTree tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	UpdateHeight(root);
	UpdateHeight(tmp);
	root = tmp;
}
void RRotate(BTree &root) {
	BTree tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	UpdateHeight(root);
	UpdateHeight(tmp);
	root = tmp;
}
void Insert(BTree &root,int key) {
	if(!root) root = new BNode(key);
	else if(root->key > key) {
		Insert(root->left,key);
		UpdateHeight(root);
		if(GetBF(root) == 2) {
			if(GetBF(root->left) == -1)
				RRotate(root->left);
			LRotate(root);
		}
	} else {
		Insert(root->right,key);
		UpdateHeight(root);
		if(GetBF(root) == -2) {
			if(GetBF(root->right) == 1)
				LRotate(root->right);
			RRotate(root);
		}
	}
}
void levelOrder(BTree root,int n) {
	queue <BTree> Q;
	Q.push(root);
	bool flag = true;
	while(!Q.empty()) {
		BTree p = Q.front();
		Q.pop();
		if(p) {
			printf("%d%c",p->key,-- n > 0 ? ' ':'\n');
			Q.push(p->left);
			Q.push(p->right);
		} else {
			while(!Q.empty()) {
				p = Q.front();
				Q.pop();
				if(p) {
					flag = false;
					printf("%d%c",p->key,-- n > 0 ? ' ':'\n');
					Q.push(p->left);
					Q.push(p->right);
				}
			}
		}
	}
	printf("%s",flag ? "YES":"NO");
}
int main() {
	BTree T = NULL;
	int key;
	scanf("%d",&N);
	for(int i = 0; i < N; i ++) {
		scanf("%d",&key);
		Insert(T,key);
	}
	levelOrder(T,N);
	return 0;
}
