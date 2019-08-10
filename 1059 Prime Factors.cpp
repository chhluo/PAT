#include <iostream>
#include <cmath>
#include <map>
using namespace std;
int N;
map <int,int> mp;
bool Prime(int n) {
	if(n == 1)
		return false;
	if(n == 2)
		return true;
	for(int i = 2; i <= sqrt(n); i ++)
		if(n % i == 0)
			return false;
	return true;
}

int main() {
	cin >> N;
	int tmp = N;
	if(N == 1) {
		printf("1=1");
		return 0;
	}
	while(N != 1) {
		for(int i = 2; i <= N; i ++) {
			if(N % i == 0 && Prime(i)) {
				mp[i] ++;
				N /= i;
				break;
			}
		}
	}
	printf("%d=",tmp);
	int cnt = mp.size();
	for(auto it = mp.begin(); it != mp.end(); it ++) {
		printf("%d",it->first);
		cnt --;
		if(it->second > 1)
			printf("^%d",it->second);
		if(cnt != 0)
			printf("*");
	}
	return 0;
}
