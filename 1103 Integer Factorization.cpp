#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N,K,P;
vector <int> ans,tmp;
int Max = 0;
int fp[450],ff[450];
int fsum = 0;
void factorization(int i,int n) {
	if(i == K) {
		if(n == 0 && Max < fsum) {
			ans = tmp;
			Max = fsum;
		}
	} else {
		int e = ff[n];
		for(int f = tmp.size() == 0 ? e: min(e,tmp.back()); f >= 1; f --) {
			int p = fp[f];
			if(n - p >= (K - i - 1)) {
				tmp.push_back(f);
				fsum += f;
				factorization(i + 1,n - p);
				tmp.pop_back();
				fsum -= f;
			}
		}
	}
}
int main() {
	scanf("%d%d%d",&N,&K,&P);
	for(int i = 1; i <= N; i ++) {
		fp[i] = (int) pow(i,P);
		ff[i] = (int) pow(i,1.0 / P);
	}
	fsum = Max = 0;
	factorization(0,N);
	if(ans.size() == 0)
		printf("Impossible\n");
	else {
		printf("%d = ",N);
		for(unsigned int i = 0; i < ans.size(); i ++)
			printf("%d^%d%s",ans[i],P,i + 1 < ans.size() ? " + ":"\n");
	}
	return 0;
}
