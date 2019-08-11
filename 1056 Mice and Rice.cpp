#include <iostream>
#include <functional>
#include <map>
#include <set>
#include <queue>
using namespace std;
#define MAXN 1010
int Ng,Np,order[MAXN];
struct Mice {
	int w,r;
};
Mice M[MAXN];
set <int,greater<int>> G;
queue <int> Q,tmp;
map <int,int> mp;
int rankM(queue <int> & player) {
	if(player.size() == 1) {
		M[mp[player.front()]].r = 1;
		return 2;
	}
	queue <int>  next,tmp;
	while(!player.empty()) {
		for(int i = 0; i < Ng && !player.empty(); i ++) {
			G.insert(player.front());
			player.pop();
		}
		next.push(*G.begin());
		G.erase(G.begin());
		for(auto it = G.begin(); it != G.end(); it ++)
			tmp.push(*it);
		G.clear();
	}
	int r = rankM(next);
	int sz = tmp.size();
	while (!tmp.empty()) {
		M[mp[tmp.front()]].r = r;
		tmp.pop();
	}
	return (r + sz);
}

int main() {
	freopen("in.txt","r",stdin);
	scanf("%d%d",&Np,&Ng);
	for(int i = 0; i < Np; i ++) {
		scanf("%d",&M[i].w);
		mp[M[i].w] = i;
	}
	for(int i = 0; i < Np; i ++) {
		scanf("%d",&order[i]);
		Q.push(M[order[i]].w);
	}
	rankM(Q);
	for(int i = 0; i < Np; i ++)
		printf("%d%c",M[i].r,i + 1 < Np ? ' ':'\n');

	return 0;
}


