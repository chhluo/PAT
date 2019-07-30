#include <cstdio>
#include <stack>
using namespace std;
int main(){
	long long int a,b,c;
	stack <int> S;
	scanf("%lld%lld",&a,&b);
	c = a + b;
	if(c < 0){
		printf("-");
		c = -c;
	}
	int tmp;
	if(c == 0)
		S.push(0);
	else{
		while(c){
			tmp = c % 1000;
			S.push(tmp);
			c /= 1000;
		}
	}
	bool flag = true;
	while(!S.empty()){
		tmp = S.top();
		S.pop();
		if(flag){
			printf("%d",tmp);
			flag = false;
		}
		else
			printf("%03d",tmp);
		if(!S.empty())
			printf(",");
	}
	return 0;
}