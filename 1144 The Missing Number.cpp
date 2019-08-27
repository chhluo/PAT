#include <iostream>
using namespace std;
#define MAXN 100010
bool flag[MAXN] = {false};
int N;
int main() {
	scanf("%d",&N);
	int x;
	for(int i = 0; i < N; i ++) {
		scanf("%d",&x);
		if(x >= 0 && x <= N)
			flag[x] = true;
	}
	int i = 1;
	while(i <= N) {
		if(!flag[i])	break;
		i ++;
	}
	printf("%d",i);
	return 0;
}
