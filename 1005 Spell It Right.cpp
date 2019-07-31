#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
char s[120] = "";
char num[10][10] = {"zero","one","two","three","four",
                    "five","six","seven","eight","nine"
                   };
int main() {
	scanf("%s",s);
	int len = strlen(s);
	int sum = 0;
	for(int i = 0; i < len; i ++)
		sum += s[i] - '0';
	if(sum == 0)
		printf("%s",num[0]);
	stack <int> S;
	while(sum) {
		S.push(sum % 10);
		sum /= 10;
	}
	int tmp;
	while(!S.empty()) {
		tmp = S.top();
		S.pop();
		printf("%s%c",num[tmp],S.empty() ? '\n' : ' ');
	}
	return 0;
}
