#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXN 110
int intial[MAXN],N,target[MAXN],A[MAXN],ans[MAXN];
bool cmp(int A[],int B[],int n) {
	for(int i = 0; i < n; i ++)
		if(A[i] != B[i])
			return false;
	return true;
}
bool InsertSort() {
	bool flag = false;
	memcpy(A,intial,sizeof(int) * N);
	for(int i = 1; i < N; i ++) {
		if(A[i] < A[i - 1]) {
			int tmp = A[i],j = i - 1;
			for(; j >= 0 && tmp < A[j]; j --)
				A[j + 1] = A[j];
			A[j + 1] = tmp;
		}
		if(flag) {
			memcpy(ans,A,sizeof(int) * N);
			return true;
		} else
			flag = cmp(A,target,N);
	}
	return false;
}
void merge(int A[],int tmp[],int low,int mid,int high) {
	int i = low,j = mid,k = low;
	while(i < mid && j < high) {
		if(A[i] < A[j]) tmp[k ++] = A[i ++];
		else tmp[k ++] = A[j ++];
	}
	while(i < mid) tmp[k ++] = A[i ++];
	while(j < high) tmp[k ++] = A[j ++];
}
bool MergeSort() {
	bool flag = false;
	memcpy(A,intial,sizeof(int) * N);
	int tmp[MAXN],i,d,m;
	for(d = 1; d < N; d *= 2) {
		m = N / d * d < N ? (N / d + 1) :(N / d);
		for(i = 0; i + 2 <= m; i += 2) {
			int low = i * d;
			int mid = low + d;
			int high = min(low + 2 * d,N);
			merge(A,tmp,low,mid,high);
		}
		i = i * d;
		while(i < N) {
			tmp[i] = A[i];
			i ++;
		}
		memcpy(A,tmp,sizeof(int) * N);
		if(flag) {
			memcpy(ans,A,sizeof(int) * N);
			return true;
		} else
			flag = cmp(A,target,N);
	}
	return false;
}
int main() {
	scanf("%d",&N);
	for(int i = 0; i < N; i ++)
		scanf("%d",intial + i);
	for(int i = 0; i < N; i ++)
		scanf("%d",target + i);
	if(MergeSort()) {
		printf("Merge Sort\n");
		for(int i = 0; i < N; i ++)
			printf("%d%c",ans[i],i + 1 < N ? ' ':'\n');
	} else {
		InsertSort();
		printf("Insertion Sort\n");
		for(int i = 0; i < N; i ++)
			printf("%d%c",ans[i],i + 1 < N ? ' ':'\n');
	}
	return 0;
}
