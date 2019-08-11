#include <iostream>
#include <set>
using namespace std;
#define MAXN 51
set <int> st[MAXN];
int N,K,M;
int main() {
	scanf("%d",&N);
	int  key;
	for(int i = 1; i <= N; i ++) {
		scanf("%d",&M);
		for(int j = 0; j < M; j ++) {
			scanf("%d",&key);
			st[i].insert(key);
		}
	}
	scanf("%d",&K);
	int s1,s2,Nc,Nt;
	double s;
	for(int i = 0; i < K; i ++) {
		scanf("%d%d",&s1,&s2);
		Nt = st[s1].size() + st[s2].size();
		Nc = 0;
		for(auto it = st[s1].begin(); it != st[s1].end(); it ++)
			Nc += st[s2].find(*it) != st[s2].end();
		Nt -= Nc;
		s = 1.0 * Nc / Nt * 100;
		printf("%.1lf%%\n",s);
	}
	return 0;
}
