#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 101
int N,M,K,cnt[MAXN] = {0};
vector <int> T[MAXN];
struct Node {
	int next,level;
	Node() {}
	Node(int nn,int ll):next(nn),level(ll) {}
};
void bfs() {
	queue <Node> Q;
	Q.push(Node(1,1));
	while(!Q.empty()) {
		Node tmp = Q.front();
		Q.pop();
		cnt[tmp.level] ++;
		for(auto it = T[tmp.next].begin(); it != T[tmp.next].end(); it ++)
			Q.push(Node(*it,tmp.level + 1));
	}
}
int main() {
	scanf("%d%d",&N,&M);
	int v1,v2;
	for(int i = 0; i < M; i ++) {
		scanf("%d%d",&v1,&K);
		for(int j = 0; j < K; j ++) {
			scanf("%d",&v2);
			T[v1].push_back(v2);
		}
	}
	bfs();
	int idx = max_element(cnt,cnt + MAXN) - cnt;
	printf("%d %d",cnt[idx],idx);
	return 0;
}
