#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100010
int N;
long long int p,A[MAXN];
int main() {
	scanf("%d%lld",&N,&p);
	for(int i = 0; i < N; i ++)
		scanf("%lld",A + i);
	sort(A,A + N);
	int ans = 0;
	for(int i = 0; i < N; i ++) {
		long long tmp = p * A[i];
		int low = i,high = N - 1,lst = i;
		while(low <= high) {
			int mid = (high - low) / 2 + low;
			if(A[mid] <= tmp) {
				low = mid + 1;
				lst = mid;
			} else {
				high = mid - 1;
			}
		}
		ans = max(ans,lst - i + 1);
	}
	printf("%d",ans);
	return 0;
}

