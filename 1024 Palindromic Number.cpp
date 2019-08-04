#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long int N;
int K;
char x[200],y[200],ans[200];
void itostr(long long int n,char x[]){
	int i = 0;
	if(n == 0){
		x[0] = '0';
		x[1] = '\0';
	}else{
		while(n){
			x[i ++] = n % 10 + '0';
			n /= 10;
		}
	}
}
void add(char x[],char y[],char sum[]){
	int len = strlen(x);
	int i = 0,j,carry = 0,tmp = 0;
	for(j = 0;j < len;j ++){
		tmp = x[j] - '0' + y[j] - '0' + carry;
		carry = tmp / 10;
		sum[i ++] = tmp % 10 + '0';
	}
	if(carry){
		sum[i] = '1';
		sum[++ i] = '\0';
	}
	reverse(sum,sum + i);
}

bool palindromic(char x[]){
	int len = strlen(x);
	int left = 0, right = len -1;
	while(left < right)
		if(x[left ++] != x[right --])
			return false;
	return true;
}

int main(){
	scanf("%ld%d",&N,&K);
	itostr(N,x);
	if(palindromic(x))
		printf("%s\n0",x);
	else{
		int cnt = 0;
		while(cnt ++ < K){
			int len = strlen(x);
			for(int i = 0;i < len;i ++)
				y[i] = x[len-1-i];
			add(x,y,ans);
			if(palindromic(ans)){
				printf("%s\n%d",ans,cnt);
				return 0;
			}else{
				strcpy(x,ans);
			}
		}
		printf("%s\n%d",ans,K);
	}
	return 0;
}