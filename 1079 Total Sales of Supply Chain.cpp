#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 100010
int N;
double p,r;
struct Node {
	vector <int> child;
	int amount;
};
Node T[MAXN];
double total = 0;
void dfs(int root,int level) {
	if(T[root].child.size() == 0) {
		total += p * pow(1 + r * 0.01,level) * T[root].amount;
	} else {
		for(unsigned int i = 0; i < T[root].child.size(); i ++)
			dfs(T[root].child[i],level + 1);
	}
}
int main() {
	scanf("%d %lf %lf",&N,&p,&r);
	int K,id,amount;
	for(int i = 0; i < N; i ++) {
		scanf("%d",&K);
		if(K == 0) {
			scanf("%d",&amount);
			T[i].amount = amount;
		} else {
			for(int j = 0; j < K; j ++) {
				scanf("%d",&id);
				T[i].child.push_back(id);
			}
		}
	}
	dfs(0,0);
	printf("%.1lf",total);
	return 0;
}
