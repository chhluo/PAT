#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAXN 200
int N,K,inSeq[MAXN],preSeq[MAXN];
struct Node {
	int data;
	Node *left,*right;
	Node(int dd):data(dd),left(NULL),right(NULL) {}
};
typedef struct Node *BTree;
void buildTree(BTree & root,int pre_s,int pre_t,int in_s,int in_t) {
	if(in_s < in_t) {
		root = new Node(preSeq[pre_s]);
		int mid = in_s;
		while(mid < in_t && inSeq[mid] != preSeq[pre_s]) mid ++;
		int n = mid - in_s;
		buildTree(root->left,pre_s + 1,pre_s + 1 + n,in_s,mid);
		buildTree(root->right,pre_s + 1 + n,pre_t,mid + 1,in_t);
	}
}
bool cmp(int x,int y) {
	return abs(x) < abs(y);
}

int dfs(BTree root,bool &flag) {
	if(root == NULL)
		return 0;
	else {
		int ln = dfs(root->left,flag);
		int rn = dfs(root->right,flag);
		if(ln != rn) {
			flag = false;
			return 0;
		} else {
			if(root->data < 0) {
				if(root->left != NULL && root->left->data < 0)
					flag = false;
				if(root->right != NULL && root->right->data < 0)
					flag = false;
			}
			return rn + (root->data > 0 ? 1 : 0);
		}
	}
}

bool judge(BTree root) {
	bool flag = true;
	if(root != NULL) {
		flag = root->data > 0;
		dfs(root,flag);
	}
	return flag;
}
void destory(BTree root) {
	if(root != NULL) {
		destory(root->left);
		destory(root->right);
		delete root;
	}
}

int main() {
	scanf("%d",&K);
	for(int i = 0; i < K; i ++) {
		scanf("%d",&N);
		for(int j = 0; j < N; j ++) {
			scanf("%d",preSeq + j);
			inSeq[j] = preSeq[j];
		}
		sort(inSeq,inSeq + N,cmp);
		BTree T = NULL;
		buildTree(T,0,N,0,N);
		printf("%s\n",judge(T) ? "Yes":"No");
		destory(T);
	}
	return 0;
}

