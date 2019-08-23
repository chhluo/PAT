#include <iostream>
#include <queue>
using namespace std;
int N,cnt[1001];
typedef struct Node * BTree;
struct Node {
	int d;
	BTree left,right;
	Node(int dd):d(dd),left(NULL),right(NULL) {}
};
void Insert(BTree & root,int key) {
	if(!root)
		root = new Node(key);
	else if(root->d < key)
		Insert(root->right,key);
	else
		Insert(root->left,key);
}
struct Step {
	BTree p;
	int level;
	Step() {}
	Step(BTree pp,int ll):p(pp),level(ll) {}
};

void levelOrder(BTree root) {
	queue <Step> Q;
	Q.push(Step(root,1));
	Step tmp;
	int MaxLevel = 0;
	while(! Q.empty()) {
		tmp = Q.front();
		Q.pop();
		cnt[tmp.level] ++;
		MaxLevel = tmp.level > MaxLevel ? tmp.level :MaxLevel;
		if(tmp.p->left)	Q.push(Step(tmp.p->left,tmp.level + 1));
		if(tmp.p->right)	Q.push(Step(tmp.p->right,tmp.level + 1));
	}
	printf("%d + %d = %d",cnt[MaxLevel],cnt[MaxLevel-1],cnt[MaxLevel] + cnt[MaxLevel-1]);
}

int main() {
	scanf("%d",&N);
	BTree T = NULL;
	int key;
	for(int i =0; i < N; i ++) {
		scanf("%d",&key);
		Insert(T,key);
	}
	levelOrder(T);
	return 0;
}
