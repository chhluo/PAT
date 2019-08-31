#include <iostream>
#include <unordered_map>
#include <vector>
#define INF 0x3f3f3f3f
#define MAXN 110
using namespace std;
int N,M,K,S,D;
vector <int> G[10010];
bool vis[10010];
unordered_map <int,int> mp;
int MinDist,MinTransfer;
vector <int> path,MinPath;
void dfs(int v,int dist,int transfer) {
	if(v == D) {
		if(dist < MinDist) {
			MinDist = dist;
			MinTransfer = transfer;
			MinPath = path;
		} else if(dist == MinDist && transfer < MinTransfer) {
			MinTransfer = transfer;
			MinPath = path;
		}
	} else {
		for(unsigned int i = 0; i < G[v].size(); i ++) {
			int idx = G[v][i];
			if(!vis[idx] && dist + 1 <= MinDist) {
				vis[idx] = true;
				int tmpTransfer = transfer;
				if(path.size() >= 2) { //前一段区间和当前区间不属于同一条线路
					int sz = path.size() - 1;
					int v1 = path[sz - 1],v2 = path[sz];
					if(mp[v1 * 10000 + v2] != mp[v2 * 10000 + idx])
						tmpTransfer ++;
				}
				path.push_back(idx);
				dfs(idx,dist + 1,tmpTransfer);
				vis[idx] = false;
				path.pop_back();
			}
		}
	}
}
int main() {
	scanf("%d",&N);
	int v1,v2;
	for(int i = 1; i <= N; i ++) {
		scanf("%d %d",&K,&v1);
		for(int j = 1; j < K; j ++) {
			scanf("%d",&v2);
			G[v1].push_back(v2);
			G[v2].push_back(v1);
			mp[v1 * 10000 + v2] = i;
			mp[10000 * v2 + v1] = i;
			v1 = v2;
		}
	}
	scanf("%d",&K);
	for(int i = 0; i < K; i ++) {
		scanf("%d%d",&S,&D);
		vis[S] = true;
		MinPath.clear();
		path.push_back(S);
		MinDist = MinTransfer = INF;
		dfs(S,0,0);
		printf("%d\n",MinDist);
		for(unsigned int j = 0; j + 1 < MinPath.size();) {
			v1 = MinPath[j];
			v2 = MinPath[j + 1];
			int line = mp[v1 * 10000 + v2],tmp,p1,p2;
			unsigned int l = j + 1;
			while(l + 1 < MinPath.size()) {
				p1 = MinPath[l];
				p2 = MinPath[l + 1];
				tmp = mp[10000 * p1 + p2];
				if(tmp != line) break;
				else l ++;
			}
			if(l + 1 == MinPath.size())
				p1 = MinPath.back();
			printf("Take Line#%d from %04d to %04d.\n",line,v1,p1);
			j = l;
		}
		vis[S] = false;
		path.clear();
	}
	return 0;
}
