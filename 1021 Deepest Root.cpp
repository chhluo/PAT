#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN 10010
int N;
vector <int> G[MAXN];
vector <int> roots;
bool vis[MAXN] = {false};
struct Step{
	int level,root;
	Step(){}
	Step(int rr,int ll):root(rr),level(ll){}
};
void BuidGraph(){
	scanf("%d",&N);
	int v1,v2;
	for(int i = 1;i < N;i ++){
		scanf("%d%d",&v1,&v2);
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}
}

void dfs(int s){
	int next;
	for(unsigned int i = 0;i < G[s].size(); i ++){
		next = G[s][i];
		if(!vis[next]){
			vis[next] = true;
			dfs(next);
		}
	}
}

int cntComponents(){
	int cnt = 0;
	for(int i = 1;i <= N;i ++){
		if(!vis[i]){
			vis[i] = true;
			dfs(i);
			cnt ++;
		}
	}
	return cnt;
}

void cntDepth(){
	queue <Step> Q;
	int MaxDepth = 0;
	Step tmp;
	for(int i = 1;i <= N;i ++){
		fill(vis,vis + 1 + N,false);
		vis[i] = true;
		Q.push(Step(i,1));
		while(!Q.empty()){
			tmp = Q.front();
			Q.pop();
			for(unsigned j = 0;j < G[tmp.root].size(); j ++){
				if(!vis[G[tmp.root][j]]){
					vis[G[tmp.root][j]] = true;
					Q.push(Step(G[tmp.root][j],tmp.level + 1));
				}
			}
		}
		if(tmp.level > MaxDepth){
			MaxDepth = tmp.level;
			roots.clear();
			roots.push_back(i);
		}else if(tmp.level == MaxDepth)
			roots.push_back(i);
	}
}
int main(){
	BuidGraph();
	int cnt = cntComponents();
	if(cnt != 1)
		printf("Error: %d components",cnt);
	else{
		cntDepth();
		sort(roots.begin(),roots.end());
		for (unsigned int i = 0; i < roots.size(); i++)
			printf("%d\n",roots[i]);
	}
	return 0;
}