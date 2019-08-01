#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1001
bool G[MAXN][MAXN] = {false};
bool vis[MAXN];
int N,M,K;
void dfs(int s) {
	vis[s] = true;
	for(int i = 1; i <= N; i ++)
		if(!vis[i] && G[s][i])
			dfs(i);
}
int components(int s) {
	int cnt = 0;
	fill(vis,vis + MAXN, false);
	vis[s] = true;
	for(int i = 1; i <= N; i ++) {
		if(!vis[i]) {
			dfs(i);
			cnt ++;
		}
	}
	return cnt - 1;
}
int main() {
	scanf("%d%d%d",&N,&M,&K);
	int v1,v2;
	for(int i = 0; i < M; i ++) {
		scanf("%d%d",&v1,&v2);
		G[v1][v2] = G[v2][v1] = true;
	}
	for(int i = 0; i < K; i ++) {
		scanf("%d",&v1);
		printf("%d\n",components(v1));
	}
	return 0;
}
