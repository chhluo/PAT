#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int table1[128] = {0},table2[128] = {0};
char N[100];
int main(){
	scanf("%s",N);
	int len = strlen(N);
	for(int i = 0;i < len;i ++)
		table1[N[i]] ++;
	reverse(N,N + len);
	int tmp,carry = 0;
	for(int i = 0;i < len;i ++){
		tmp = (N[i] - '0') * 2 + carry;
		if(tmp >= 10){
			N[i] = tmp % 10 + '0';
			carry = 1;
		}else{
			carry = 0;
			N[i] = tmp + '0';
		}
	}
	if(carry){
		N[len] = '1';
		N[++ len] = '\0';
	}
	for(int i = 0;i < len;i ++)
		table2[N[i]] ++;
	bool flag = true;
	for(int i = '0';i <= '9';i ++)
		if(flag && table1[i] != table2[i])
			flag = false;
	reverse(N,N + len);
	printf("%s\n%s",flag?"Yes":"No",N);
	return 0;
}