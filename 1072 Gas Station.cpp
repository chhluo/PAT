#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
#define MAXN 1020
#define INF 0x3f3f3f3f
int N,M,K,Ds;
struct Road {
	int next,len;
	Road() {}
	Road(int nn,int ll):next(nn),len(ll) {}
};
vector <Road> G[MAXN];
int dis[MAXN];
bool vis[MAXN];

void dijkstra(int S,int &MinDis,double &avg) {
	fill(dis,dis + MAXN,INF);
	fill(vis,vis + MAXN,false);
	for(auto it = G[S].begin(); it != G[S].end(); it ++)
		dis[it->next] = it->len;
	vis[S] = true;
	vis[S] = 0;
	while(1) {
		int Min = INF,idx = -1;
		for(int i = 1; i <= N + K; i ++)
			if(!vis[i] && dis[i] < Min) {
				idx = i;
				Min = dis[i];
			}
		if(idx == -1) break;
		vis[idx] = true;
		for(auto it = G[idx].begin(); it != G[idx].end(); it ++)
			if(!vis[it->next] && dis[idx] + it->len < dis[it->next]) {
				dis[it->next] = dis[idx] + it->len;
			}
	}
	MinDis = INF,avg = 0;
	for(int i = 1; i <= N; i ++) {
		if(dis[i] > Ds) {
			MinDis = avg = INF;
			return;
		} else {
			MinDis = min(dis[i],MinDis);
			avg += dis[i];
		}
	}
	avg /= N;
}

int main() {
	scanf("%d%d%d%d\n",&N,&K,&M,&Ds);
	int v1,v2,len;
	char s1[10],s2[10];
	for(int i = 0; i < M; i ++) {
		scanf("%s %s %d",s1,s2,&len);
		v1 = s1[0] == 'G' ? atoi(s1 + 1) + N :atoi(s1);
		v2 = s2[0] == 'G' ? atoi(s2 + 1) + N :atoi(s2);
		G[v1].push_back(Road(v2,len));
		G[v2].push_back(Road(v1,len));
	}
	int MinDis,ansDis;
	double avg,ansAvg;
	int idx = -1;
	for(int i = N + 1; i <= N + K; i ++) {
		dijkstra(i,MinDis,avg);
		if(MinDis != INF) {
			if(idx == -1) {
				idx = i;
				ansDis = MinDis;
				ansAvg = avg;
			} else {
				if(MinDis > ansDis) {
					idx = i;
					ansDis = MinDis;
					ansAvg = avg;
				} else if(MinDis == ansDis && avg < ansAvg) {
					idx = i;
					ansAvg = avg;
				}
			}
		}
	}
	if(idx == -1)
		printf("No Solution\n");
	else
		printf("G%d\n%.1lf %.1lf\n",idx - N,(double)ansDis,ansAvg);
	return 0;
}
