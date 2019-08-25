#include <iostream>
#include <set>
using namespace std;
int N;
multiset <int> mst;
int main() {
	scanf("%d",&N);
	int v;
	for(int i = 0; i < N; i ++) {
		scanf("%d",&v);
		mst.insert(v);
	}
	int v1,v2;
	while (N > 1) {
		v1 = *mst.begin();
		mst.erase(mst.begin());
		v2 = *mst.begin();
		mst.erase(mst.begin());
		mst.insert((v1 + v2) / 2);
		N --;
	}
	printf("%d",*mst.begin());
	return 0;
}
