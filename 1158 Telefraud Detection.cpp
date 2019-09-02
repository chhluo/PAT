#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define MAXN 1010
int N,M,K;
int SHORT = 5;
int G[MAXN][MAXN] = {0};
int S[MAXN];
map <int,set<int>> mp;
vector <set<int>> ans;
bool cmp(set <int> &st1,set <int> &st2) {
	return *st1.begin() < *st2.begin();
}
void Init() {
	for(int i = 0; i < MAXN; i ++)
		S[i] = -1;
}
int Find(int S[],int x) {
	if(S[x] == -1) return x;
	return S[x] = Find(S,S[x]);
}
void Union(int S[],int x1,int x2) {
	int r1 = Find(S,x1);
	int r2 = Find(S,x2);
	if(r1 != r2)
		S[r1] = r2;
}
int main() {
	Init();
	scanf("%d%d%d",&K,&N,&M);
	int v1,v2,lst;
	for(int i = 0; i < M; i ++) {
		scanf("%d%d%d",&v1,&v2,&lst);
		G[v1][v2] += lst;
	}
	vector <int> suspect;
	for(int i = 1; i <= N; i ++) {
		vector <int> V;
		for(int j = 1; j <= N; j ++)
			if(j != i && G[i][j] > 0 && G[i][j] <= SHORT)
				V.push_back(j);

		if((int) V.size() > K) {
			int cnt = 0;
			for(auto it = V.begin(); it != V.end(); it ++)
				if(G[*it][i] > 0)
					cnt ++;

			if(cnt <= (V.size() * 0.2))
				suspect.push_back(i);
		}
	}
	for(unsigned int i = 0; i < suspect.size(); i ++) {
		for(unsigned int j = i + 1; j < suspect.size(); j ++) {
			if(G[suspect[i]][suspect[j]] > 0 && G[suspect[j]][suspect[i]] > 0)
				Union(S,suspect[i],suspect[j]);
		}
	}
	for(unsigned int i = 0; i < suspect.size(); i ++) {
		int r1 = Find(S,suspect[i]);
		mp[r1].insert(suspect[i]);
	}
	for(auto mit = mp.begin(); mit != mp.end(); mit ++)
		ans.push_back(mit->second);
	sort(ans.begin(),ans.end(),cmp);
	if(ans.size() == 0)
		printf("None");
	else {
		for(unsigned int i = 0; i < ans.size(); i ++) {
			unsigned int j = 0;
			for(auto sit = ans[i].begin(); sit != ans[i].end(); sit ++,j ++)
				printf("%d%c",*sit,j + 1 < ans[i].size() ? ' ':'\n');
		}
	}
	return 0;
}
