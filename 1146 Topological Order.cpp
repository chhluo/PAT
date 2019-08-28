#include <iostream>
#include <vector>
#include <cstring>
#define MAXN 1010
using namespace std;
int N,K,M,seq[MAXN],degree[MAXN] = {0},tmp[MAXN] = {0};
vector <int> G[MAXN],ans;
bool judge(int degree[],int seq[]) {
	for(int i = 0; i < N; i ++) {
		if(degree[seq[i]] != 0)
			return false;
		else {
			int idx = seq[i];
			for(auto it = G[idx].begin(); it != G[idx].end(); it ++)
				degree[*it] --;
		}
	}
	return true;
}

int main() {
	scanf("%d%d",&N,&M);
	int v1,v2;
	for(int i = 0; i < M; i ++) {
		scanf("%d%d",&v1,&v2);
		G[v1].push_back(v2);
		degree[v2] ++;
	}
	scanf("%d",&K);
	for(int i = 0; i < K; i ++) {
		for(int j = 0; j < N; j ++)
			scanf("%d", seq + j);
		memcpy(tmp,degree,sizeof(tmp));
		if(!judge(tmp,seq)) ans.push_back(i);
	}
	for(unsigned int i = 0; i < ans.size(); i ++)
		printf("%d%c",ans[i],i + 1 < ans.size() ? ' ':'\n');
	return 0;
}

