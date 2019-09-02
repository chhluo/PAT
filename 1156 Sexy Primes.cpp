#include <iostream>
#include <cmath>
using namespace std;
int N;
bool Prime(int n) {
	if(n == 1) return false;
	else if(n == 2) return true;
	else {
		int e = (int) sqrt(n);
		for(int i = 2; i <= e; i ++)
			if(n % i == 0)
				return false;
		return true;
	}
}

int main() {
	cin >> N;
	if(Prime(N) && N - 6 > 0 && Prime(N - 6))
		printf("Yes\n%d",N - 6);
	else if(Prime(N) && Prime(N + 6))
		printf("Yes\n%d",N + 6);
	else {
		while(1) {
			N ++;
			if(Prime(N) && (N - 6 > 0 && Prime(N - 6) || Prime(N + 6)))
				break;
		}
		printf("No\n%d",N);
	}
	return 0;
}
