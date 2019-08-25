#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 500010
int N,M;
struct Couple {
	bool flag;
	int spouse;
};
Couple C[MAXN];
vector <int> guest,ans;
int main() {
	scanf("%d",&N);
	int v1,v2;
	for(int i = 0; i < N; i ++) {
		scanf("%d%d",&v1,&v2);
		C[v1].spouse = v2;
		C[v2].spouse = v1;
	}
	scanf("%d",&M);
	for(int i = 0; i < M; i ++) {
		scanf("%d",&v1);
		guest.push_back(v1);
		C[v1].flag = true;
	}
	for(unsigned int i = 0; i < guest.size(); i ++) {
		v2 = C[guest[i]].spouse;
		if(!C[v2].flag)
			ans.push_back(guest[i]);
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(unsigned int i = 0; i < ans.size(); i ++)
		printf("%05d%c",ans[i],i + 1 < ans.size() ? ' ': '\n');
	return 0;
}
