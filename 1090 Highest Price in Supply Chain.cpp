#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define MAXN 100010
int N,MaxDepth,cnt;
double p,r;
vector <int> T[MAXN];

void dfs(int root,int depth) {
	if(T[root].size() == 0) {
		if(depth > MaxDepth) {
			cnt = 1;
			MaxDepth = depth;
		} else if(depth == MaxDepth)
			cnt ++;
	} else {
		for(unsigned int i = 0; i < T[root].size(); i ++)
			dfs(T[root][i],depth + 1);
	}
}
int main() {
	scanf("%d %lf %lf",&N,&p,&r);
	int v,root;
	for(int i = 0; i < N; i ++) {
		scanf("%d",&v);
		if(v == -1)
			root = i;
		else
			T[v].push_back(i);
	}
	dfs(root,0);
	printf("%.2lf %d",p * pow(1 + 0.01 * r,MaxDepth),cnt);
	return 0;
}

