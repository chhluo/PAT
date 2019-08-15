#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 40010
int N,M,K;
struct Appliant {
	int gt,ge,gi,chioce[5];
};
Appliant apt[MAXN];
int idx[MAXN];
bool cmp(int x,int y) {
	if(apt[x].gt != apt[y].gt) 	return apt[x].gt > apt[y].gt;
	else return apt[x].ge > apt[y].ge;
}
struct School {
	int quota;
	vector <int> app;
};
School S[101];
int main() {
	scanf("%d%d%d",&N,&M,&K);
	for(int i = 0; i < M; i ++)
		scanf("%d",&S[i].quota);
	for(int i = 0; i < N; i ++) {
		scanf("%d%d",&apt[i].ge,&apt[i].gi);
		apt[i].gt = apt[i].ge + apt[i].gi;
		for(int j = 0; j < K; j ++)
			scanf("%d",&apt[i].chioce[j]);
		idx[i] = i;
	}
	sort(idx,idx + N,cmp);
	for(int i = 0; i < N; i ++) {
		for(int j = 0; j < K; j ++) {
			int c = apt[idx[i]].chioce[j];
			if((int) S[c].app.size() < S[c].quota) {
				S[c].app.push_back(idx[i]);
				break;
			} else if(S[c].quota != 0 && (int) S[c].app.size() >= S[c].quota) {
				int lst = S[c].app.back();
				if(apt[lst].gt == apt[idx[i]].gt && apt[lst].ge == apt[idx[i]].ge) {
					S[c].app.push_back(idx[i]);
					break;
				}
			}
		}
	}
	for(int i = 0; i < M; i ++) {
		if(S[i].app.size() == 0)
			printf("\n");
		else {
			sort(S[i].app.begin(),S[i].app.end());
			for(unsigned int j = 0; j < S[i].app.size(); j ++)
				printf("%d%c",S[i].app[j],j + 1 < S[i].app.size() ? ' ':'\n');
		}
	}
	return 0;
}
