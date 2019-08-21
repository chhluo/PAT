#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
using namespace std;
#define MAXN 10010
int N,A[MAXN],matrix[1000][1000];
void findMN(int &m,int &n) {
	int e = sqrt(N),d = 0x3fffffff;
	int tmpm,tmpn;
	for(n = 1; n <= e; n ++) {
		for(m = n; m <= N; m ++) {
			if(m * n == N && m - n < d) {
				tmpm = m;
				tmpn = n;
			}
		}
	}
	m = tmpm;
	n = tmpn;
}

void fillMatrix(int seq[],int h,int w,int i,int j) {
	if(w == 0)	return;
	if(w == 1) {
		for(int v = i; v < i + h; v ++,seq ++)
			matrix[v][j] = *seq;
		return;
	}
	for(int v = j; v < j + w; v ++,seq ++)
		matrix[i][v] = *seq;
	for(int v = i + 1; v < i + h; v ++,seq ++)
		matrix[v][j + w - 1] = *seq;
	for(int v = j + w - 2; v >= j; v --,seq ++)
		matrix[i + h - 1][v] = *seq;
	for(int v = i + h - 2; v > i; v --,seq ++)
		matrix[v][j] = *seq;
	fillMatrix(seq,h-2,w-2,i+1,j+1);
}

int main() {
	scanf("%d",&N);
	for(int i = 0; i < N; i ++)
		scanf("%d",A + i);
	int m,n;
	findMN(m,n);
	sort(A,A + N,greater<int>());
	fillMatrix(A,m,n,0,0);
	for(int i = 0; i < m; i ++)
		for(int j = 0; j < n; j ++)
			printf("%d%c",matrix[i][j],j + 1 < n ? ' ' : '\n');

	return 0;
}
