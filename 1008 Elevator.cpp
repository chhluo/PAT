#include <cstdio>
using namespace std;
int N;
int main() {
	scanf("%d",&N);
	int nowFloor = 0,nextFloor,total = 0,diff;
	for(int i = 0; i < N; i ++) {
		scanf("%d",&nextFloor);
		diff = nextFloor - nowFloor;
		total += (diff > 0)?(diff * 6 + 5):(-diff * 4 + 5);
		nowFloor = nextFloor;
	}
	printf("%d",total);
	return 0;
}
