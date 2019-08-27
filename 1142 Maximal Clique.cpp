#include <iostream>
#include <set>
using namespace std;
#define MAX 210
int Nv,Ne,M,K,V[MAX];
bool G[MAX][MAX] = {false};
void judge(int V[],int K,bool &Clique,bool &Maximal) {
	set <int> st;
	for(int i = 0; i < K; i ++) {
		st.insert(V[i]);
		for(int j = i + 1; j < K; j ++) {
			if(!G[V[i]][V[j]]) {
				Clique = false;
				return ;
			}
		}
	}
	for(int i = 1; i <= Nv; i ++) {
		auto it = st.find(i);
		if(it == st.end()) {
			int cnt = 0;
			for(int j = 0; j < K; j ++) 
				cnt += G[i][V[j]];
			if(cnt == K) {
				Maximal = false;
				return;
			}
		}
	}
}
int main() {
	scanf("%d%d",&Nv,&Ne);
	int v1,v2;
	for(int i = 0; i < Ne; i ++) {
		scanf("%d%d",&v1,&v2);
		G[v1][v2] = G[v2][v1] = true;
	}
	scanf("%d",&M);
	for(int i = 0; i < M; i ++) {
		scanf("%d",&K);
		for(int j = 0; j < K; j ++)
			scanf("%d",V + j);
		bool Maximal = true,Clique = true;
		judge(V,K,Clique,Maximal);
		if(!Clique) printf("Not a Clique\n");
		else if(!Maximal) printf("Not Maximal\n");
		else printf("Yes\n");
	}
	return 0;
}
