#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 510
#define INF 0x3f3f3f3f
int N,M,S,D;
struct Road {
	int next,len,time;
	Road() {}
	Road(int nn,int ll,int tt):next(nn),len(ll),time(tt) {}
};
vector <Road> G[MAXN];
bool vis[MAXN];
vector <int> ShortestP,FastestP,Path;
int MinDist,MinT;
void DijkstraS(int V) {
	int *dist = new int[MAXN],*pre = new int[MAXN],*time = new int[MAXN];
	fill(dist,dist + MAXN,INF);
	fill(vis,vis + MAXN,false);
	for(auto it = G[V].begin(); it != G[V].end(); it ++) {
		dist[it->next] = it->len;
		pre[it->next] = V;
	}
	vis[V] = true;
	pre[V] = -1;
	dist[V] = 0;
	time[V] = 0;
	while(1) {
		int Min = INF,idx = -1;
		for(int i = 0; i < N; i ++) {
			if(!vis[i] && dist[i] < Min) {
				idx = i;
				Min = dist[i];
			}
		}
		if(idx == -1)	break;
		vis[idx] = true;
		for(auto it = G[idx].begin(); it != G[idx].end(); it ++) {
			if(!vis[it->next]) {
				if(dist[idx] + it->len < dist[it->next]) {
					dist[it->next] = dist[idx] + it->len;
					pre[it->next] = idx;
					time[it->next] = dist[idx] + it->time;
				} else if(dist[idx] + it->len == dist[it->next] && time[it->next] > dist[idx] + it->time) {
					time[it->next] = dist[idx] + it->time;
					pre[it->next] = idx;
				}
			}
		}
	}
	int p = D;
	while(pre[p] != -1) {
		ShortestP.push_back(p);
		p = pre[p];
	}
	reverse(ShortestP.begin(),ShortestP.end());
	MinDist = dist[D];
	delete [] pre,delete [] dist,delete []time;
}
void DijkstraF(int V) {
	int *cnt = new int[MAXN],*pre = new int[MAXN],*time = new int[MAXN];
	fill(time,time + MAXN,INF);
	fill(vis,vis + MAXN,false);
	for(auto it = G[V].begin(); it != G[V].end(); it ++) {
		time[it->next] = it->time;
		cnt[it->next] = 0;
		pre[it->next] = V;
	}
	vis[V] = true;
	pre[V] = -1;
	cnt[V] = 0;
	time[V] = 0;
	while(1) {
		int Min = INF,idx = -1;
		for(int i = 0; i < N; i ++) {
			if(!vis[i] && time[i] < Min) {
				idx = i;
				Min = time[i];
			}
		}
		if(idx == -1)	break;
		vis[idx] = true;
		for(auto it = G[idx].begin(); it != G[idx].end(); it ++) {
			if(!vis[it->next]) {
				if(time[idx] + it->time < time[it->next]) {
					time[it->next] = time[idx] + it->time;
					pre[it->next] = idx;
					cnt[it->next] = cnt[idx] + 1;
				} else if(time[idx] + it->time == time[it->next] && cnt[it->next] > cnt[idx] + 1) {
					cnt[it->next] = cnt[idx] + 1;
					pre[it->next] = idx;
				}
			}
		}
	}
	int p = D;
	while(pre[p] != -1) {
		FastestP.push_back(p);
		p = pre[p];
	}
	reverse(FastestP.begin(),FastestP.end());
	MinT= time[D];
	delete [] pre,delete [] cnt,delete []time;
}

int main() {
	scanf("%d%d",&N,&M);
	int v1,v2,onew,len,time;
	for(int i = 0; i < M; i ++) {
		scanf("%d%d%d%d%d",&v1,&v2,&onew,&len,&time);
		G[v1].push_back(Road(v2,len,time));
		if(onew == 0) G[v2].push_back(Road(v1,len,time));
	}
	scanf("%d%d",&S,&D);
	DijkstraS(S);
	DijkstraF(S);
	if(ShortestP == FastestP) {
		printf("Distance = %d; Time = %d: %d",MinDist,MinT,S);
		for(auto it = ShortestP.begin(); it != ShortestP.end(); it ++)
			printf(" -> %d",*it);
	} else {
		printf("Distance = %d: %d",MinDist,S);
		for(auto it = ShortestP.begin(); it != ShortestP.end(); it ++)
			printf(" -> %d",*it);
		printf("\nTime = %d: %d",MinT,S);
		for(auto it = FastestP.begin(); it != FastestP.end(); it ++)
			printf(" -> %d",*it);
	}
	return 0;
}
