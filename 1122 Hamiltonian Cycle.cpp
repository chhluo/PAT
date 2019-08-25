#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define MAXN 210
int N,M,K;
bool G[MAXN][MAXN] = {false};
vector <int> path;
bool judge(vector <int> &path) {
	if(path.size() < N + 1)	return false;
	if(path.front() != path.back()) return false;
	set <int> st;
	for(unsigned int i = 1; i < path.size(); i ++) {
		auto it = st.find(path[i]);
		if(it != st.end())	return false;
		else st.insert(path[i]);
		if(!G[path[i-1]][path[i]])	return false;
	}
	return true;
}
int main() {
	scanf("%d%d",&N,&M);
	int v1,v2;
	for(int i = 0; i < M; i ++) {
		scanf("%d%d",&v1,&v2);
		G[v1][v2] = G[v2][v1] = true;
	}
	scanf("%d",&K);
	int n;
	for(int i = 0; i < K; i ++) {
		scanf("%d",&n);
		path.clear();
		for(int j = 0; j < n; j ++) {
			scanf("%d",&v1);
			path.push_back(v1);
		}
		printf("%s\n",judge(path) ? "YES":"NO");
	}
	return 0;
}
