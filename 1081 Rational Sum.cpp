#include <iostream>
#include <cmath>
using namespace std;
int N;
struct Value {
	long long int numerator,denominator,integer;
};
Value A,B;
void simplify(Value & X) {
	long long int i = 1;
	X.integer += X.numerator / X.denominator;
	X.numerator %= X.denominator;
	while(1) {
		for(i = 2; i <= abs(X.denominator) && i <= abs(X.numerator); i ++)
			if(X.denominator % i == 0 && X.numerator % i == 0) {
				X.denominator /= i;
				X.numerator /= i;
				i = 2;
				break;
			}
		if(i > X.denominator || i > X.numerator)
			break;
	}
}
int main() {
	scanf("%d",&N);
	long long tmp;
	for(int i = 0; i < N; i ++) {
		scanf("%lld/%lld",&B.numerator,&B.denominator);
		if(i == 0) {
			A = B;
			simplify(A);
		} else {
			tmp = A.numerator * B.denominator + A.denominator * B.numerator;
			A.denominator *= B.denominator;
			A.numerator = tmp;
			simplify(A);
		}
	}
	if(A.numerator == 0)	printf("%lld",A.integer);
	else if(A.integer == 0) 	printf("%lld/%lld",A.numerator,A.denominator);
	else 	printf("%lld %lld/%lld",A.integer,A.numerator,A.denominator);
	return 0;
}

