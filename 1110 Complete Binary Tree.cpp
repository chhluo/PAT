#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
#define MAXN 30
int N;
struct Node {
	int left,right,id;
};
Node T[MAXN];
bool flag[MAXN] = {false};
void levelOrder(int root) {
	queue <int> Q;
	Q.push(root);
	int idx,last;
	bool f = true;
	while(!Q.empty()) {
		idx = Q.front();
		Q.pop();
		if(idx != -1) {
			last = idx;
			Q.push(T[idx].left);
			Q.push(T[idx].right);
		} else {
			while(!Q.empty()) {
				idx = Q.front();
				Q.pop();
				if(idx != -1)	break;
			}
			if(idx != -1) break; 
			}
	}
	printf("%s %d",f ? "YES":"NO",f ? last : root);
}

int main() {
	scanf("%d\n",&N);
	char s1[5],s2[5];
	int v1,v2;
	for(int i = 0; i < N; i ++) {
		scanf("%s %s",s1,s2);
		if(s1[0] != '-') {
			v1 = stoi(s1);
			flag[v1] = true;
			T[i].left = v1;
		} else
			T[i].left = -1;
		if(s2[0] != '-') {
			v2 = stoi(s2);
			flag[v2] = true;
			T[i].right = v2;
		} else
			T[i].right = -1;
	}
	int root = min_element(flag,flag + N) - flag;
	levelOrder(root);
	return 0;
}
