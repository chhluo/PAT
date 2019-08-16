#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int N;
vector <int> pre,in,post;
void solve(int ps,int pe,int zs,int ze) {
	if(ps < pe) {
		int pos = zs;
		while(pos < ze) {
			if(pre[ps] == in[pos])
				break;
			pos ++;
		}
		int n = pos - zs;
		solve(ps + 1,ps + 1 + n,zs,pos);
		solve(ps + 1 + n,pe,pos + 1,ze);
		post.push_back(pre[ps]);
	}
}
int main() {
	scanf("%d\n",&N);
	stack <int> S;
	char s[10];
	int key;
	for(int i = 0; i < 2 * N; i ++) {
		scanf("%s",s);
		if(s[1] == 'u') {
			scanf("%d\n",&key);
			pre.push_back(key);
			S.push(key);
		} else {
			in.push_back(S.top());
			S.pop();
		}
	}
	solve(0,N,0,N);
	for(int i = 0; i < N; i ++)
		printf("%d%c",post[i],i + 1 < N ? ' ':'\n');
	return 0;
}
