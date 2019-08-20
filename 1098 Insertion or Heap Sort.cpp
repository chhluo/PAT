#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 110
int N,intial[MAXN],target[MAXN],ans[MAXN],tmp[MAXN];
bool cmp(int A[],int B[],int n) {
	for(int i = 1; i <= n; i ++)
		if(A[i] != B[i])
			return false;
	return true;
}
bool InsertSort() {
	memcpy(tmp,intial,sizeof(intial));
	bool flag = false;
	for(int i = 2; i <= N; i ++) {
		int j = i - 1;
		if(tmp[j + 1] < tmp[j]) {
			tmp[0] = tmp[j + 1];
			for(; tmp[j] > tmp[0]; j --)
				tmp[j + 1] = tmp[j];
			tmp[j + 1] = tmp[0];
		}
		if(flag) {
			memcpy(ans,tmp,sizeof(ans));
			return true;
		} else
			flag = cmp(target,tmp,N);
	}
	return false;
}
void adjust(int A[],int s,int e) {
	A[0] = A[s];
	int i,j;
	for(i = s; 2 * i <= e;) {
		j = i * 2;
		if(j + 1 <= e && A[j + 1] > A[j])
			j ++;
		if(A[j] < A[0])
			break;
		else {
			A[i] = A[j];
			i = j;
		}
	}
	A[i] = A[0];
}
void createHeap(int A[]) {
	for(int i = N / 2; i > 0; i --)
		adjust(A,i,N);
}
bool heapSort() {
	memcpy(tmp,intial,sizeof(tmp));
	createHeap(tmp);
	bool flag = false;
	for(int i = N; i > 0; i --) {
		swap(tmp[i],tmp[1]);
		adjust(tmp,1,i - 1);
		if(flag) {
			memcpy(ans,tmp,sizeof(ans));
			return true;
		} else
			flag = cmp(target,tmp,N);
	}
	return false;
}
int main() {
	scanf("%d",&N);
	for(int i = 1; i <= N; i ++)
		scanf("%d",intial + i);
	for(int i = 1; i <= N; i ++)
		scanf("%d",target + i);
	if(InsertSort()) {
		printf("Insertion Sort\n");
		for(int i = 1; i <= N; i ++)
			printf("%d%c",ans[i],i < N ? ' ':'\n');
	} else {
		heapSort();
		printf("Heap Sort\n");
		for(int i = 1; i <= N; i ++)
			printf("%d%c",ans[i],i < N ? ' ':'\n');
	}
	return 0;
}
