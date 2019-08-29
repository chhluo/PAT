#include <iostream>
#include <set>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 210
#define INF 0x3f3f3f3f
int N,M,K,G[MAXN][MAXN];
void judge(vector<int> &path,int &dist,bool &cycle,bool &SimpleC) {
	cycle = path.front() == path.back() && path.size() >= N + 1;
	set <int> st;
	int v1,v2;
	for(unsigned int i = 1; i < path.size(); i ++) {
		v1 = path[i-1],v2 = path[i];
		auto it = st.find(v1);
		SimpleC = it == st.end();
		if(G[v1][v2] == INF) {
			cycle = SimpleC = false;
			dist = INF;
			break;
		} else {
			dist += G[v1][v2];
		}
		st.insert(v1);
	}
	if(cycle)
		cycle = st.size() == N;//是不是访问了所有点
}
int main() {
	scanf("%d%d",&N,&M);
	int v1,v2,len;
	memset(G,INF,sizeof(G));
	for(int i = 0; i < M; i ++) {
		scanf("%d%d%d",&v1,&v2,&len);
		G[v1][v2] = G[v2][v1] = len;
	}
	scanf("%d",&K);
	vector <int> path;
	int n,MinD = INF,idx;
	for(int i = 1; i <= K; i ++) {
		scanf("%d",&n);
		path.clear();
		for(int j = 0; j < n; j ++) {
			scanf("%d",&v1);
			path.push_back(v1);
		}
		bool cycle = true,SimpleC = true;
		int dist = 0;
		judge(path,dist,cycle,SimpleC);
		if(dist < MinD && cycle) {
			MinD = dist;
			idx = i;
		}
		printf("Path %d: ",i);
		if(SimpleC && cycle) printf("%d (TS simple cycle)\n",dist);
		else if(!SimpleC && cycle) printf("%d (TS cycle)\n",dist);
		else if(!cycle && dist != INF) printf("%d (Not a TS cycle)\n",dist);
		else printf("NA (Not a TS cycle)\n");
	}
	printf("Shortest Dist(%d) = %d\n",idx,MinD);
	return 0;
}
