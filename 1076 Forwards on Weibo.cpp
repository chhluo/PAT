#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN  1010
int N,L,M,K,id;
vector <int> G[MAXN];
bool vis[MAXN];
struct Step {
	int next,step;
	Step() {}
	Step(int nn,int ss):next(nn),step(ss) {}
};
int bfs(int S) {
	queue <Step> Q;
	Step tmp;
	Q.push(Step(S,0));
	int cnt = -1;
	fill(vis,vis + N + 1,false);
	vis[S] = true;
	while(!Q.empty()) {
		tmp = Q.front();
		Q.pop();
		if(tmp.step > L)
			break;
		cnt ++;
		for(unsigned int i = 0; i < G[tmp.next].size(); i ++) {
			if(!vis[G[tmp.next][i]]) {
				Q.push(Step(G[tmp.next][i],tmp.step + 1));
				vis[G[tmp.next][i]] = true;
			}
		}
	}
	return cnt;
}

int main() {
	scanf("%d%d",&N,&L);
	for(int i = 1; i <= N; i ++) {
		scanf("%d",&M);
		for(int j = 0; j < M; j ++) {
			scanf("%d",&id);
			G[id].push_back(i);
		}
	}
	scanf("%d",&K);
	for(int i = 0; i < K; i ++) {
		scanf("%d",&id);
		printf("%d\n",bfs(id));
	}
	return 0;
}
