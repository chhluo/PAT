#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define MAXN 100010
int N;
vector <int> T[MAXN];
double p,r;
int cnt = 0,Minlevel = 0x3f3f3f3f;
void dfs(int root,int level) {
	if(T[root].size() == 0) {
		if(level < Minlevel) {
			Minlevel = level;
			cnt = 1;
		} else if(level == Minlevel)
			cnt ++;
	} else {
		for(auto it = T[root].begin(); it != T[root].end(); it ++)
			dfs(*it,level + 1);
	}
}

int main() {
	scanf("%d%lf%lf",&N,&p,&r);
	int K,id;
	for(int i = 0; i < N; i ++) {
		scanf("%d",&K);
		for(int j = 0; j < K; j ++) {
			scanf("%d",&id);
			T[i].push_back(id);
		}
	}
	dfs(0,0);
	printf("%.4lf %d",p * pow(1 + r * 0.01,Minlevel),cnt);
	return 0;
};
