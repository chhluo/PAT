#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int N;
vector <int> ans,tmp,a;
bool Prime(int n) {
	if(n == 1)	return false;
	else if(n == 2)	return true;
	else {
		int end = sqrt(n);
		for(int i = 2; i <= end; i ++)
			if(n % i == 0)
				return false;
		return true;
	}
}
int main() {
	scanf("%d",&N);
	int m = Prime(N) ? 0:(int) sqrt(N); //如果是很大的素数，循环就会很多次
	for(int i = 2; i < m; i ++) {
		if(pow(i,ans.size()) >= N)	break;
		int factor = i,n = N;
		tmp.clear();
		while(n != 1 && n >= factor) {
			if(n % factor == 0) {
				tmp.push_back(factor);
				n /= factor;
			}
			factor ++;
		}
		int s = 0,d = 0;
		a.clear();
		while(s < (int) tmp.size()) {
			d = s + 1;
			while(d <(int) tmp.size() && tmp[d - 1] + 1 == tmp[d])
				d ++;
			if(d - s > (int) a.size()) {
				a.clear();
				for(int l = s; l < d; l ++)
					a.push_back(tmp[l]);
			}
			s = d;
		}
		if(a.size() > ans.size())
			ans = a;
	}
	if(ans.size() == 0)
		ans.push_back(N);
	printf("%d\n",ans.size());
	for(unsigned int i = 0; i < ans.size(); i ++)
		printf("%d%c",ans[i],i + 1 < ans.size() ? '*':'\n');
	return 0;
}
