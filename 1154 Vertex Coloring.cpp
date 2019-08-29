#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define MAXN 10010
int N,M,K,color[MAXN];
vector <int> G[MAXN];
int judge(int color[]) {
	set <int> st;
	for(int i = 0; i < N; i ++) {
		st.insert(color[i]);
		for(unsigned int j = 0; j < G[i].size(); j ++)
			if(color[i] == color[G[i][j]])
				return -1;
	}
	return st.size();
}
int main() {
	scanf("%d%d",&N,&M);
	int v1,v2;
	for(int i = 0; i < M; i ++) {
		scanf("%d%d",&v1,&v2);
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}
	scanf("%d",&K);
	for(int i = 0; i < K; i ++) {
		for(int j = 0; j < N; j ++)
			scanf("%d",color + j);
		int k = judge(color);
		if(k != -1) printf("%d-coloring\n",k);
		else printf("No\n");
	}
	return 0;
}

