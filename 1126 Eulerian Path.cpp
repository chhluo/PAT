#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define MAXN 510
int N,M,degree[MAXN] = {0};
vector <int> G[MAXN];
bool vis[MAXN] = {false};
void dfs(int V) {
	for(unsigned int i = 0; i < G[V].size(); i ++) {
		if(!vis[G[V][i]]) {
			vis[G[V][i]] = true;
			dfs(G[V][i]);
		}
	}
}
bool connected() {
	int cnt = 0;
	for(int i = 1; i <= N; i ++) {
		if(!vis[i]) {
			vis[i] = true;
			dfs(i);
			cnt ++;
		}
	}
	return cnt == 1;
}
int main() {
	scanf("%d%d",&N,&M);
	int v1,v2;
	for(int i = 0; i < M; i ++) {
		scanf("%d%d",&v1,&v2);
		G[v1].push_back(v2);
		G[v2].push_back(v1);
		degree[v1] ++;
		degree[v2] ++;
	}
	int cnt = 0;
	for(int i = 1; i <= N; i ++) {
		printf("%d%c",degree[i],i < N ? ' ':'\n');
		cnt += (degree[i] % 2);
	}
	if(!connected())
		printf("Non-Eulerian");
	else {
		if(cnt == 0) printf("Eulerian");
		else if(cnt == 2) printf("Semi-Eulerian");
		else printf("Non-Eulerian");
	}
	return 0;
}
