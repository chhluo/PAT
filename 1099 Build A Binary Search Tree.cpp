#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN 110
int N,keys[MAXN];
struct Node {
	int d,left,right;
};
Node T[MAXN];
int cnt = 0;
void BuildTree(int root) {
	if(root != -1) {
		if(T[root].left != -1)
			BuildTree(T[root].left);
		T[root].d = keys[cnt ++];
		if(T[root].right != -1)
			BuildTree(T[root].right);
	}
}
void levelOrder() {
	queue <int> Q;
	Q.push(0);
	while(! Q.empty()) {
		int idx = Q.front();
		Q.pop();
		printf("%d%c",T[idx].d,(-- cnt > 0 ) ? ' ' : '\n');
		if(T[idx].left != -1)
			Q.push(T[idx].left);
		if(T[idx].right != -1)
			Q.push(T[idx].right);
	}
}
int main() {
	scanf("%d",&N);
	int left,right;
	for(int i = 0; i < N; i ++) {
		scanf("%d%d",&left,&right);
		T[i].left = left;
		T[i].right = right;
	}
	for(int i = 0; i < N; i ++)
		scanf("%d",keys + i);
	sort(keys,keys + N);
	BuildTree(0);
	levelOrder();
	return 0;
}
