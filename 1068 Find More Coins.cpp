#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 10010
using namespace std;
int N,M,A[MAXN],total;
bool status[MAXN][101] = {false},flag = false;
vector <int> path,ans;
void dfs(int s) {
	if(total == M) {
		flag = true;
		ans = path;
	} else {
		for(int i = s + 1; i < N; i ++) {
			int tmp = total + A[i];
			if(!flag && tmp <= M && !status[i][tmp]) {
				total = tmp;
				status[i][tmp] = true;
				path.push_back(A[i]);
				dfs(i);
				path.pop_back();
				total -= A[i];
			}
		}
	}
}

int main() {
	scanf("%d%d",&N,&M);
	for(int i = 0; i < N; i ++)
		scanf("%d", A + i);
	sort(A,A + N);
	for(int i = 0; i < N; i ++) {
		path.clear();
		total = A[i];
		if(!flag && !status[i][total]) {
			path.push_back(A[i]);
			status[i][total] = true;
			dfs(i);
		}
	}
	if(flag) {
		for(unsigned int i = 0; i < ans.size(); i ++)
			printf("%d%c",ans[i],i + 1 < ans.size() ? ' ':'\n');
	} else
		printf("No Solution\n");
	return 0;
}
