#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 510
#define INF 0x3f3f3f3f
int N,M,C1,C2;
int Resc[MAXN],cntRoads[MAXN] = {0};
bool vis[MAXN] = {false};
int dist[MAXN], MaxResc[MAXN];
struct Road {
	int next,len;
	Road(int next_,int len_):next(next_),len(len_) {}
};
vector <Road> G[MAXN];
void Dijkstra() {
	fill(dist,dist + MAXN,INF);
	dist[C1] = 0;
	cntRoads[C1] = 1;
	for(int i = 0; i < N; i ++)
		MaxResc[i] = Resc[i];
	while (true) {
		int idx = -1,Min = INF;
		for(int i = 0; i < N; i ++) {
			if(!vis[i] && dist[i] < Min) {
				idx = i;
				Min = dist[i];
			}
		}
		if(idx == C2)
			break;
		vis[idx] = true;
		for(unsigned int i = 0; i < G[idx].size(); i ++) {
			int next = G[idx][i].next;
			if(!vis[next]) {
				if(dist[next] > dist[idx] + G[idx][i].len) {
					dist[next] = dist[idx] + G[idx][i].len;
					cntRoads[next] = cntRoads[idx];
					MaxResc[next] = MaxResc[idx] + Resc[next];
				} else if(dist[next] == dist[idx] + G[idx][i].len) {
					cntRoads[next] += cntRoads[idx];
					MaxResc[next] = max(MaxResc[next],MaxResc[idx] + Resc[next]);
				}
			}
		}
	}
}

int main() {
	scanf("%d%d%d%d",&N,&M,&C1,&C2);
	for(int i = 0; i < N; i ++)
		scanf("%d",Resc + i);
	int v1,v2,len;
	for(int i = 0; i < M; i ++) {
		scanf("%d%d%d",&v1,&v2,&len);
		G[v1].push_back(Road(v2,len));
		G[v2].push_back(Road(v1,len));
	}
	Dijkstra();
	printf("%d %d",cntRoads[C2],MaxResc[C2]);
	return 0;
}
