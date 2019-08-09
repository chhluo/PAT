#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#define MAXN 101
int N,M,S;
struct Node {
	int w;
	vector <int> child;
};
Node T[MAXN];
vector <int> path;
int w;
bool cmp(int X,int Y) {
	return T[X].w > T[Y].w;
}

void printPath() {
	for(unsigned int i = 0; i < path.size(); i ++)
		printf("%d%c",path[i],i + 1 < path.size() ? ' ' : '\n');
}
void dfs(int root) {
	path.push_back(T[root].w);
	w += T[root].w;
	if(T[root].child.size() == 0 && w == S) {
		printPath();
	} else {
		for(unsigned int i = 0; i < T[root].child.size(); i ++)
			dfs(T[root].child[i]);
	}
	path.pop_back();
	w -= T[root].w;
}

int main() {
	scanf("%d%d%d",&N,&M,&S);
	for(int i = 0; i < N; i ++)
		scanf("%d",&T[i].w);
	int id,k,kid;
	for(int i = 0; i < M; i ++) {
		scanf("%d%d",&id,&k);
		for(int j = 0; j < k; j ++) {
			scanf("%d",&kid);
			T[id].child.push_back(kid);
		}
		sort(T[id].child.begin(),T[id].child.end(),cmp);
	}
	w = 0;
	dfs(0);

	return 0;
}

