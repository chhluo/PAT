#include <iostream>
#include <set>
#define MAXN 50010
using namespace std;
int N,K,cnt[MAXN] = {0};
struct Rule {
	bool operator () (int x,int y) {
		if(cnt[x] != cnt[y])
			return cnt[x] > cnt[y];
		else
			return x < y;
	}
};
set <int,Rule> st;
int main() {
	scanf("%d%d",&N,&K);
	int x;
	scanf("%d",&x);
	cnt[x] ++;
	st.insert(x);
	for(int i = 1; i < N; i ++) {
		scanf("%d",&x);
		printf("%d:",x);
		int j = 0;
		for(auto it = st.begin(); it != st.end() && j < K; it ++,j ++)
			printf(" %d",*it);
		printf("\n");
		auto it = st.find(x);
		if(it != st.end()) st.erase(it);
		cnt[x] ++;
		st.insert(x);
	}
	return 0;
}
