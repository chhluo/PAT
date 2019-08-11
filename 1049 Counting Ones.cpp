#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
char S[20];
int dp[20] = {0};

int permuation(int n) {
	if(n == 0 || n == 1)
		return 1;
	int product = 1;
	for(int i = 2; i <= n; i ++)
		product *= i;
	return product;
}

int combination(int n,int i) {
	return permuation(n) / (permuation(n-i) * permuation(i));
}

int sumCombination(int n) {
	int sum = 0;
	for(int i = 1; i <= n; i ++)
		sum += i * combination(n,i) * ((int) pow(9,n-i));
	return sum;
}

void solve(int n) {
	int l = n;
	while(S[l] == '0') //±£Ö¤S[l] != '0'
		l --;
	if(l == 0)
		dp[n] = 0;
	else if(l == 1) {
		dp[n] = 1;
	} else {
		if(S[l] == '1') {
			char tmp[20];
			memcpy(tmp,S + 1,l - 1);
			int len = l - 1;
			while(tmp[len - 1] == '0')
				len --;
			if(len == 0) {
				dp[n] = sumCombination(n-1) + 1;
			} else {
				tmp[len] = '\0';
				reverse(tmp,tmp + len);
				dp[n] = atoi(tmp) + dp[len] + (sumCombination(l-1) + 1);
			}
		} else {
			dp[n] = (S[n] - '0') * sumCombination(n-1) + ((int) pow(10,n-1)) + dp[n-1];
		}
	}
}

int main() {
	scanf("%s",S + 1);
	int n = strlen(S + 1);
	reverse(S + 1,S + 1 + n);
	for(int i = 1; i <= n; i ++) {
		solve(i);
		//	printf("dp[%d] = %d\n",i,dp[i]);
	}
	printf("%d",dp[n]);
	return 0;
}
