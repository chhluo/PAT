#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 110
int N,said[MAXN],status[MAXN];

int main() {
	scanf("%d",&N);
	for(int i = 1; i <= N; i ++)
		scanf("%d",said + i);
	int w1 = N + 1,w2 = N + 1;
	for(int i = 1; i <= N; i ++) {
		for(int j = i + 1; j <= N; j ++) {
			vector <int> lie;
			fill(status, status + MAXN,1);
			status[i] = -1;
			status[j] = -1;
			for(int l = 1; l <= N; l ++) {
				int idx = abs(said[l]);
				int s = said[l] > 0 ? 1 : -1;
				if(status[idx] != s) lie.push_back(l);
			}
			if(lie.size() == 2 && status[lie[0]] + status[lie[1]] == 0) {
				printf("%d %d",i,j);
				return 0;
			}
		}
	}
	printf("No Solution");
	return 0;
}
