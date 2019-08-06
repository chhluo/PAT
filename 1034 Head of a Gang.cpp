#include <iostream>
#include <map>
#include <string>
#include <set>
using namespace std;
#define MAXN 2010 //1000条记录，最多2000个顶点
int N,K,Nv = 0,gangW;
map <string,int> smpi;
map <int,string> imps;
int G[MAXN][MAXN] = {0};
bool vis[MAXN] = {false};
set <Node> ans;
map <int,int> gang;
int StoIDX(string s) {
	int v;
	auto it = smpi.find(s);
	if(it == smpi.end()) {
		smpi[s] = Nv;
		imps[Nv] = s;
		v = Nv ++;
	} else
		v = it->second;
	return v;
}
struct Node {
	string head;
	int num;
	Node(string hh,int nn):head(hh),num(nn) {}
	bool operator < (Node X)const {
		return this->head < X.head;
	}
};
void dfs(int v) {
	int headw = 0;
	for(int i = 0; i < Nv; i ++) {
		gangW += G[v][i];
		headw += G[v][i];
		if(!vis[i] && G[v][i] > 0) {
			vis[i] = true;
			dfs(i);
		}
	}
	gang[v] = headw;
}
void solve() {
	for(int i = 0; i < Nv; i ++) {
		if(!vis[i]) {
			gangW = 0;
			gang.clear();
			vis[i] = true;
			dfs(i);
			if(gangW > 2 * K && gang.size() > 2) {
				auto head = gang.begin();
				for(auto it = gang.begin(); it != gang.end(); it ++)
					if(it->second > head->second)
						head = it;
				ans.insert(Node(imps[head->first],gang.size()));
			}
		}
	}
}

int main() {
	cin >> N >> K;
	string sv1,sv2;
	int v1,v2, w;
	for(int i = 0; i < N; i ++) {
		cin >> sv1 >> sv2 >> w;
		v1 = StoIDX(sv1);
		v2 = StoIDX(sv2);
		G[v1][v2] += w;
		G[v2][v1] += w;
	}
	solve();
	printf("%d\n",ans.size());
	for(auto it = ans.begin(); it != ans.end(); it ++)
		printf("%s %d\n",it->head.c_str(),it->num);
	return 0;
}
