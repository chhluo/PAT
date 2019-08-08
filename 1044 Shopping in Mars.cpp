#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 100010
int N,M,D[MAXN];
struct Node {
	int i,j,s;
	Node(int ii,int jj,int ss):i(ii),j(jj),s(ss) {}
	bool operator < (Node X) const {
		return this->i < X.i;
	}
};
vector <Node> ans;
int main() {
	scanf("%d%d",&N,&M);
	for(int l = 1; l <= N; l ++)
		scanf("%d",D + l);
	int sum = 0,Min = 0x3f3f3f3f;
	int i = 1,j = 0;
	while(i <= N) {
		while(j <= N) {
			sum += D[++ j];
			if(sum >= M)
				break;
		}
		//	printf("%d %d %d\n",i,j,sum);
		if(sum >= M && j <= N) {
			if(sum < Min) {
				Min = sum;
				ans.clear();
				ans.push_back(Node(i,j,sum));
			} else if(sum == Min)
				ans.push_back(Node(i,j,sum));
		} else
			break;
		while(i <= j && sum > M) {
			sum -= D[i ++];
			if(sum >= M) {
				if(sum < Min) {
					Min = sum;
					ans.clear();
					ans.push_back(Node(i,j,sum));
				} else if(sum == Min)
					ans.push_back(Node(i,j,sum));
			}
		}
	}
	sort(ans.begin(), ans.end());
	for(auto it = ans.begin(); it != ans.end(); it ++)
		printf("%d-%d\n",it->i,it->j);

	return 0;
}
