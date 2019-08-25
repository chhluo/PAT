#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 50
int N,in[MAXN],post[MAXN];
typedef struct BNode *BTree;
struct BNode {
	int key;
	BTree left,right;
	BNode(int kk):key(kk),left(NULL),right(NULL) {}
};
void BuildTree(BTree &root,int in_s,int in_t,int post_s,int post_t) {
	if(in_s < in_t) {
		root = new BNode(post[post_t - 1]);
		int pos = in_s;
		while(pos < in_t) {
			if(in[pos] == post[post_t - 1])	break;
			else pos ++;
		}
		int n = pos - in_s;
		BuildTree(root->left,in_s,pos,post_s,post_s + n);
		BuildTree(root->right,pos + 1,in_t,post_s + n,post_t - 1);
	}
}
struct Step {
	BTree p;
	int level;
	Step() {}
	Step(BTree pp,int ll):p(pp),level(ll) {}
};
void Zigzag(BTree root) {
	Step Q[MAXN];
	int head = 0,rear = 0,cnt[MAXN] = {0};
	Q[rear ++] = Step(root,1);
	while(head < rear) {
		Step tmp = Q[head ++];
		cnt[tmp.level] ++;
		if(tmp.p->left) Q[rear ++] = Step(tmp.p->left,tmp.level + 1);
		if(tmp.p->right) Q[rear ++] = Step(tmp.p->right,tmp.level + 1);
	}
	int i = 1,MaxLevel = Q[rear - 1].level,S = 0,T;
	while(i <= MaxLevel) {
		T = S + cnt[i];
		if(i % 2 == 0) {
			for(int j = S; j < T; j ++)
				printf("%d%c",Q[j].p->key,-- N > 0 ? ' ':'\n');
		} else {
			for(int j = T - 1; j >= S; j --)
				printf("%d%c",Q[j].p->key,-- N > 0 ? ' ':'\n');
		}
		i ++;
		S = T;
	}
}
int main() {
	BTree T = NULL;
	scanf("%d",&N);
	for(int i = 0; i < N; i ++)
		scanf("%d", in + i);
	for(int i = 0; i < N; i ++)
		scanf("%d",post + i);
	BuildTree(T,0,N,0,N);
	Zigzag(T);
	return 0;
}
