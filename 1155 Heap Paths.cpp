#include <iostream>
#include <vector>
using namespace std;
#define MAXN 1010
int N,T[MAXN];
vector <int> path;
void dfs(int r,bool &MaxHeap,bool &MinHeap) {
	if(r <= N) {
		path.push_back(T[r]);
		int left = 2 * r,right = 2 * r + 1;
		if(right > N && left > N) {
			for(unsigned int i = 0; i < path.size(); i ++)
				printf("%d%c",path[i],i + 1 < path.size() ? ' ':'\n');
		}
		if(right <= N) {
			if(MaxHeap && T[r] < T[right]) MaxHeap = false;
			if(MinHeap && T[r] > T[right]) MinHeap = false;
			dfs(right,MaxHeap,MinHeap);
		}
		if(left <= N) {
			if(MaxHeap && T[r] < T[left]) MaxHeap = false;
			if(MinHeap && T[r] > T[left]) MinHeap = false;
			dfs(left,MaxHeap,MinHeap);
		}
		path.pop_back();
	}
}
int main() {
	scanf("%d",&N);
	for(int i = 1; i <= N; i ++)
		scanf("%d",T + i);
	bool MaxHeap = true,MinHeap = true;
	dfs(1,MaxHeap,MinHeap);
	if(MaxHeap && !MinHeap) printf("Max Heap");
	else if(!MaxHeap && MinHeap) printf("Min Heap");
	else printf("Not Heap");
	return 0;
}
