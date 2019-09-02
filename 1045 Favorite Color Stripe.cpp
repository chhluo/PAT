#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
int N,M,L,color[210],stripe[10010],w[10010];
set <int> st;
int pos[210];
vector <int> v[210];
int Max = 0,Len = 0;
int dp[210] = {0};
void dfs(int n,int p) {
	if(n == -1) {
		dp[n + 1] = max(dp[n + 1],Len);
	} else {
		if(dp[n+1] > Len) return;
		else dp[n+1] = Len;
		dfs(n-1,p);
		int sum = 0;
		for(int i = v[n].size() - 1; i >= 0; i --) {
			if(v[n][i] < p) {
				sum += w[v[n][i]];
				Len += sum;
				dfs(n-1,v[n][i]);
				Len -= sum;
			}
		}
	}
}
int main() {
	scanf("%d%d",&N,&M);
	for(int i = 1; i <= M; i ++) {
		scanf("%d",color + i);
		pos[color[i]] = i;
		st.insert(color[i]);
	}
	scanf("%d",&L);
	int p = 0,pre = -1,c,cnt = 1;
	for(int i = 0; i < L; i ++) {
		scanf("%d",&c);
		auto it = st.find(c);
		if(it != st.end()) {
			if(pre != c) {
				pre = c;
				p ++;
				w[p - 1] = cnt;
				stripe[p] = c;
				cnt = 1;
			} else {
				cnt ++;
			}
		}
	}
	w[p] = cnt;
	L = p;
	for(int i = 1; i <= L; i ++) {
		int idx = pos[stripe[i]];
		v[idx].push_back(i);
	}
	dfs(M,L+1);
	printf("%d",dp[0]);
	return 0;
}
