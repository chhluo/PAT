#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,cnt[50] = {0};
vector <int> ans;
int SumDigit(int x) {
	int sum = 0;
	while(x) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

int main() {
	scanf("%d",&N);
	int x;
	for(int i = 0; i < N; i ++) {
		scanf("%d",&x);
		cnt[SumDigit(x)] ++;
	}
	for(int i = 0; i < 50; i ++)
		if(cnt[i] > 0)
			ans.push_back(i);
	printf("%d\n",ans.size());
	for(unsigned int i = 0; i < ans.size(); i ++)
		printf("%d%c",ans[i],i + 1 < ans.size() ? ' ':'\n');
	return 0;
}
