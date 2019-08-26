#include <iostream>
#include <string>
#include <algorithm>
#define MAXN 30
using namespace std;
struct Node {
	string data;
	int left,right;
};
Node T[MAXN];
int N;
bool flag[MAXN] = {false};
void InOrder(int root,int level) {
	if(root != -1) {
		if((T[root].left != -1 || T[root].right != -1) && level > 1)
			printf("(");
		InOrder(T[root].left,level + 1);
		printf("%s",T[root].data.c_str());
		InOrder(T[root].right,level + 1);
		if((T[root].left != -1 || T[root].right != -1) && level > 1)
			printf(")");
	}
}
int main() {
	cin >> N;
	for(int i = 1; i <= N; i ++) {
		cin >> T[i].data >> T[i].left >> T[i].right;
		if(T[i].left != -1)	flag[T[i].left] = true;
		if(T[i].right != -1) flag[T[i].right] = true;
	}
	int root = min_element(flag + 1, flag + 1 + N) - flag;
	InOrder(root,1);
	return 0;
}
