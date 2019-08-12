#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXN 1010
int N,A[MAXN],ans[MAXN];
int height(int n) {
	int sum = 1;
	int h = 1;
	while(sum < n)
		sum += (int) pow(2,h ++);
	return h;
}
void buildTree(int pos,int seq[],int start,int end) {
	if(start < end) {
		int n = end - start;
		int h = height(n);
		int ln,rn;
		if(h == 1) {
			ln = rn = 0;
		} else {
			int last = n -  ((int) pow(2,h-1) - 1);
			if(last > (((int) pow(2,h-1)) / 2)) {
				ln = ((int) pow(2,h-1)) / 2;
				rn = last - ln;
			} else {
				ln = last;
				rn = 0;
			}
			ln += (int) pow(2,h-2) - 1;
			rn += (int) pow(2,h-2) - 1;
		}
		ans[pos] = seq[start + ln];
		buildTree(2 * pos,seq,start,start + ln);
		buildTree(2 * pos + 1,seq,start + ln + 1,end);
	}
}
int main() {
	scanf("%d",&N);
	for(int i = 0; i < N; i ++)
		scanf("%d",A + i);
	sort(A,A + N);
	buildTree(1,A,0,N);
	for(int i = 1; i <= N; i ++)
		printf("%d%c",ans[i],i < N ? ' ':'\n');
	return 0;
}
