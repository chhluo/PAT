#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define MAXN 320
using namespace std;
int N,M,K;
bool gender[10000] = {false};//true ÄÐ£¬false Å®
struct Pair {
	int first,second;
	bool operator < (Pair X) const {
		return X.first != this->first ? this->first < X.first : this->second < X.second;
	}
};
set <Pair> ans;
vector <int> G[10000];
bool vis[10000] = {false};
Pair tmp;
void dfs(int p1,int p2,int v,int depth) {
	for(unsigned int i = 0; i < G[v].size(); i ++) {
		int idx = G[v][i];
		if(!vis[idx]) {
			vis[idx] = true;
			if(depth == 1 && idx != p2 && gender[p1] == gender[idx]) {
				tmp.first = idx;
				dfs(p1,p2,idx,depth + 1);
			} else if(depth == 2 &&  gender[p2] == gender[idx]) {
				tmp.second = idx;
				dfs(p1,p2,idx,depth + 1);
			} else if(depth == 3 && idx == p2) {
				ans.insert(tmp);
			}
			vis[idx] = false;
		}
	}
}
int main() {
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&N,&M);
	int v1,v2;
	char s1[6],s2[6];
	for(int i = 0; i < M; i ++) {
		scanf("%s%s",s1,s2);
		v1 = abs(atoi(s1));
		v2 = abs(atoi(s2));
		if(s1[0] != '-') gender[v1] = true;
		if(s2[0] != '-') gender[v2] = true;
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}
	scanf("%d",&K);
	for(int i = 0; i < K; i ++) {
		scanf("%d%d",&v1,&v2);
		v1 = abs(v1);
		v2 = abs(v2);
		ans.clear();
		vis[v1] = true;
		dfs(v1,v2,v1,1);
		vis[v1] = false;
		printf("%d\n",ans.size());
		for(auto it = ans.begin(); it != ans.end(); it ++)
			printf("%04d %04d\n",it->first,it->second);
	}
	return 0;
}

