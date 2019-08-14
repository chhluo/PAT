#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 10010
int N,M,K,P[10];
struct Node {
	int uid,ts,rk,pf,s[6];
	bool ps[6],pc[6],f;
};
Node Testee[MAXN];
vector <int> ans;
bool cmp(int X,int Y) {
	if(Testee[X].ts != Testee[Y].ts)
		return Testee[X].ts > Testee[Y].ts;
	else if(Testee[X].pf != Testee[Y].pf)
		return Testee[X].pf > Testee[Y].pf;
	else
		return Testee[X].uid < Testee[Y].uid;
}
int main() {
	scanf("%d%d%d",&N,&K,&M);
	for(int i = 1; i <= K; i ++)
		scanf("%d",P + i);
	int id,pid,s;
	for(int i = 0; i < M; i ++) {
		scanf("%d%d%d",&id,&pid,&s);
		Testee[id].uid = id;
		if(s != -1) {
			Testee[id].f = true;
			Testee[id].ps[pid] = true;
			Testee[id].pc[pid] = true;
			if(Testee[id].s[pid] < s)
				Testee[id].s[pid] = s;
		} else {
			Testee[id].ps[pid] = true;
		}

	}
	for(int i = 1; i <= N; i ++) {
		if(Testee[i].f) {
			for(int j = 1; j <= K; j ++)
				if(Testee[i].ps[j] && Testee[i].pc[j]) {
					Testee[i].ts += Testee[i].s[j];
					if(Testee[i].s[j] == P[j])
						Testee[i].pf ++;
				}
			ans.push_back(i);
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	Testee[ans[0]].rk = 1;
	for(unsigned int i = 1; i < ans.size(); i ++) {
		if(Testee[ans[i]].ts == Testee[ans[i-1]].ts)
			Testee[ans[i]].rk = Testee[ans[i-1]].rk;
		else
			Testee[ans[i]].rk = i + 1;
	}
	for(unsigned int i = 0; i < ans.size(); i ++) {
		printf("%d %05d %d",Testee[ans[i]].rk,Testee[ans[i]].uid,Testee[ans[i]].ts);
		for(int j = 1; j <= K; j ++)
			if(Testee[ans[i]].ps[j])
				printf(" %d",Testee[ans[i]].s[j]);
			else
				printf(" -");
		printf("\n");
	}
	return 0;
}
