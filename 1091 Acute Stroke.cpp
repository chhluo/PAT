#include <iostream>
#include <queue>
using namespace std;
#define MAXM 1300
#define MAXN 140
#define MAXL 70
int N,M,L,T,V,tmpV;
bool G[MAXM][MAXN][MAXL];
int dir[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
void dfs(int m,int n,int l) { //�ᱬջ
	if(m < 0 || m > M || n < 0 || n > N || l < 0 || l > L) 	return;
	if(!G[m][n][l]) return;
	tmpV ++;
	G[m][n][l] = false;
	for(int i = 0; i < 6; i ++)
		dfs(m + dir[i][0],n + dir[i][1],l + dir[i][2]);
}
struct Step {
	int m,n,l;
	Step() {}
	Step(int mm,int nn,int ll):m(mm),n(nn),l(ll) {}
};

int bfs(int m,int n,int l) {
	if(m < 0 || m > M || n < 0 || n > N || l < 0 || l > L)
		return 0;
	if(!G[m][n][l])	return 0;
	int cnt = 0;
	queue <Step> Q;
	Q.push(Step(m,n,l));
	G[m][n][l] = false;
	Step tmp;
	while(!Q.empty()) {
		tmp = Q.front();
		Q.pop();
		cnt ++;
		for(int i = 0; i < 6; i ++) {
			m = tmp.m + dir[i][0],n = tmp.n + dir[i][1],l = tmp.l + dir[i][2];
			if(m < 0 || m > M || n < 0 || n > N || l < 0 || l > L) 	continue;
			if(!G[m][n][l]) continue;
			G[m][n][l] = false;
			Q.push(Step(m,n,l));
		}
	}
	return cnt;
}

void dfsTraverse() {
	V = 0;
	for(int l = 0; l < L; l ++)
		for(int i = 0; i < M; i ++)
			for(int j = 0; j < N; j ++) {
				tmpV = bfs(i,j,l);
				if(tmpV >= T) V += tmpV;
			}
}

int main() {
	scanf("%d%d%d%d",&M,&N,&L,&T);
	int v;
	for(int l = 0; l < L; l ++)
		for(int i = 0; i < M; i ++)
			for(int j = 0; j < N; j ++) {
				scanf("%d",&v);
				G[i][j][l] = v == 1;
			}
	dfsTraverse();
	printf("%d",V);
	return 0;
}
