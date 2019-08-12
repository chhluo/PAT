#include <iostream>
using namespace std;
int T;
long long A,B,C;
int main() {
	scanf("%d",&T);
	bool flag;
	for(int i = 1; i <= T; i ++) {
		scanf("%lld %lld %lld",&A,&B,&C);
		if(A >= 0 && B >= 0 && C >= 0)
			flag = A > C - B;
		if(A >= 0 && B >= 0 && C < 0)
			flag = true;
		if(A >= 0 && B < 0 && C >= 0)
			flag = A + B > C;
		if(A >= 0 && B < 0 && C < 0)
			flag = A + B > C;
		if(A < 0 && B >= 0 && C >= 0)
			flag = A + B > C;
		if(A < 0 && B >= 0 && C < 0)
			flag = A + B > C;
		if(A < 0 && B < 0 && C >= 0)
			flag = false;
		if(A < 0 && B < 0 && C < 0)
			flag = A > C - B;
		printf("Case #%d: %s\n",i,flag ? "true":"false");
	}
	return 0;
}
