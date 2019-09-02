#include <iostream>
using namespace std;
int N1,N2;
int A1[200001],A2[200001],A[400002];
int main() {
	scanf("%d",&N1);
	for(int i = 0; i < N1; i ++)
		scanf("%d",A1 + i);
	scanf("%d",&N2);
	for(int i = 0; i < N2; i ++)
		scanf("%d",A2 + i);
	int k = 0,mid = (N1 + N2 - 1) / 2;
	int i = 0,j = 0;
	while(i < N1 && j < N2) {
		if(A1[i] < A2[j])
			A[k ++] = A1[i ++];
		else
			A[k ++] = A2[j ++];
	}
	while(i < N1) A[k ++] = A1[i ++];
	while(j < N2) A[k ++] = A2[j ++];
	printf("%d",A[mid]);
	return 0;
}
