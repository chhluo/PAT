#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN 20
int N;
struct Node {
	int left,right;
};
Node T[MAXN];
bool flag[MAXN] = {false};
void reverseBT(int root) {
	if(root != -1) {
		reverseBT(T[root].left);
		reverseBT(T[root].right);
		swap(T[root].left,T[root].right);
	}
}
void levelOrder(int root) {
	int cnt = 0,idx;
	queue <int> Q;
	Q.push(root);
	while(!Q.empty()) {
		idx = Q.front();
		printf("%d%c",idx,++ cnt < N ? ' ' : '\n');
		Q.pop();
		if(T[idx].left != -1)
			Q.push(T[idx].left);
		if(T[idx].right != -1)
			Q.push(T[idx].right);
	}
}
void inOrder(int root) {
	if(root != -1) {
		inOrder(T[root].left);
		printf("%d%c",root,-- N > 0 ? ' ':'\n');
		inOrder(T[root].right);
	}
}
int main() {
	scanf("%d\n",&N);
	char s[10];
	for(int i = 0; i < N; i ++) {
		fgets(s,10,stdin);
		if(s[0] != '-') {
			flag[s[0] - '0'] = true;
			T[i].left = s[0] - '0';
		} else
			T[i].left = -1;
		if(s[2] != '-') {
			flag[s[2] - '0'] = true;
			T[i].right = s[2] - '0';
		} else
			T[i].right = -1;
	}
	int root = min_element(flag,flag + N) - flag;
	reverseBT(root);
	levelOrder(root);
	inOrder(root);
	return 0;
}
