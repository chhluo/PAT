#include <iostream>
#include <vector>
using namespace std;
#define MAXN 1010
int N,M,seq[MAXN];
vector <int> ans;
void postOrder(int r, bool &MaxHeap,bool &MinHeap) {
	if(r <= N) {
		int left = 2 * r,right = 2 * r + 1;
		if(left <= N) {
			if(MaxHeap && seq[r] < seq[left]) MaxHeap = false;
			if(MinHeap && seq[r] > seq[left]) MinHeap = false;
			postOrder(left,MaxHeap,MinHeap);
		}
		if(right <= N) {
			if(MaxHeap && seq[r] < seq[right]) MaxHeap = false;
			if(MinHeap && seq[r] > seq[right]) MinHeap = false;
			postOrder(right,MaxHeap,MinHeap);
		}
		ans.push_back(seq[r]);
	}
}
void judge() {
	bool MaxHeap = true,MinHeap = true;
	ans.clear();
	postOrder(1,MaxHeap,MinHeap);
	if(MaxHeap && !MinHeap) printf("Max Heap\n");
	else if(MinHeap && !MaxHeap) printf("Min Heap\n");
	else printf("Not Heap\n");
	for(unsigned int i = 0; i < ans.size(); i ++)
		printf("%d%c",ans[i],i + 1 < ans.size() ? ' ':'\n');
}
int main() {
	scanf("%d%d",&M,&N);
	for(int i = 0; i < M; i ++) {
		for(int j = 1; j <= N; j ++)
			scanf("%d",seq + j);
		judge();
	}
	return 0;
}
