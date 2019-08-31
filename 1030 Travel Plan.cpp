#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 510
using namespace std;
int N,M,S,D;
struct Road {
	int d,c,e;
	Road() {}
	Road(int dd,int cc,int ee):d(dd),c(cc),e(ee) {}
};
vector <vector <Road> > G(MAXN);
bool visited[MAXN] = {false};
int minDistance,distances,minCost,cost;
vector <int> path,minPath;
void Dfs(int start) {
	if(start == D) {
		if(distances < minDistance || (distances == minDistance && cost < minCost)) {
			minDistance = distances;
			minCost = cost;
			minPath = path;
		}
		return;
	}
	Road tmp;
	for(int i = 0; i < G[start].size(); i ++) {
		tmp = G[start][i];
		if(visited[tmp.e] || distances  + tmp.d > minDistance)
			continue;

		visited[tmp.e] = true;
		distances += tmp.d;
		cost += tmp.c;
		path.push_back(tmp.e);
		Dfs(tmp.e);
		visited[tmp.e] = false;
		distances -= tmp.d;
		cost -= tmp.c;
		path.pop_back();
	}
}
int main() {
//	freopen("in.txt","r",stdin);
	scanf("%d%d%d%d",&N,&M,&S,&D);
	int s,e,d,c;
	for(int i = 0; i < M; i ++) {
		scanf("%d%d%d%d",&s,&e,&d,&c);
		G[s].push_back(Road(d,c,e));
		G[e].push_back(Road(d,c,s));
	}
	minDistance = minCost = 1 << 30;
	distances = cost = 0;
	visited[S] = true;
	path.push_back(S);
	Dfs(S);
	for(int i = 0; i < minPath.size(); i ++)
		printf("%d ",minPath[i]);
	printf("%d %d",minDistance,minCost);
	return 0;
}

