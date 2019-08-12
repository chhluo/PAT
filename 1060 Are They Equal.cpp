#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
char A[200],B[200],SA[200],SB[200];
int main() {
	scanf("%d %s %s",&N,A,B);
	int lena = strlen(A),lenb = strlen(B);
	int fpa = find(A,A + lena,'.') - A;
	int fpb = find(B,B + lenb,'.') - B;
	int idxa = 0,idxb = 0;
	while(A[idxa] == '.' || A[idxa] == '0') idxa ++;
	while(B[idxb] == '.' || B[idxb] == '0') idxb ++;
	int cnta = (fpa - idxa < 0 ? fpa - idxa + 1 :fpa - idxa);
	int cntb = fpb - idxb < 0 ? fpb - idxb + 1:fpb - idxb;
	if(idxa < fpa && fpa != lena) { //12.3456->123456
		for(int i = fpa; i < lena - 1; i ++)
			A[i] = A[i + 1];
		lena --;
	}
	if(idxb < fpb && fpb != lenb) { //123->
		for(int i = fpb; i < lenb - 1; i ++)
			B[i] = B[i + 1];
		lenb --;
	}
	while(lena - idxa < N) {
		A[lena ++] = '0';
	}
	A[N + idxa] = 0;
	while(lenb - idxb < N) {
		B[lenb ++] = '0';
	}
	B[N + idxb] = 0;
	bool flag = true;
	for(int i = 0; i < N; i ++)
		if(A[i + idxa] != B[i + idxb]) {
			flag = false;
			break;
		}
	if(flag)
		printf("YES 0.%s*10^%d",A + idxa,cnta);
	else
		printf("NO 0.%s*10^%d 0.%s*10^%d",A + idxa,cnta,B + idxb,cntb);
	return 0;
}
