#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 10010
int N,M,K,v1,v2;
vector <int> G[MAXN];
bool flag[MAXN][MAXN] = {false};
bool judge(vector <int> & V) {
	for(unsigned int i = 0; i < V.size(); i ++) {
		int v1 = V[i],v2;
		for(unsigned int j = 0; j < G[v1].size(); j ++) {
			v2 = G[v1][j];
			flag[v1][v2] = flag[v2][v1] = false;
		}
	}
	for(int i = 0; i < N; i ++) {
		for(unsigned int j = 0; j < G[i].size(); j ++) {
			if(flag[i][G[i][j]] || flag[G[i][j]][i])
				return false;
		}
	}
	return true;
}

void Reset() {
	for(int i = 0; i < N; i ++) {
		for(unsigned int j = 0; j < G[i].size(); j ++) {
			flag[i][G[i][j]]=flag[G[i][j]][i] = true;
		}
	}
}

int main() {
	scanf("%d%d",&N,&M);
	for(int i = 0; i < M; i ++) {
		scanf("%d%d",&v1,&v2);
		G[v1].push_back(v2);
		G[v2].push_back(v1);
		flag[v1][v2] = flag[v2][v1] = true;
	}
	scanf("%d",&K);
	for(int i = 0; i < K; i ++) {
		vector <int> V;
		int n,x;
		scanf("%d",&n);
		for(int j = 0; j < n; j ++) {
			scanf("%d",&x);
			V.push_back(x);
		}
		Reset();
		printf("%s\n",judge(V) ? "Yes":"No");
	}
	return 0;
}
