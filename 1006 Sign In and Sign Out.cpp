#include <cstdio>
#include <cstring>
using namespace std;
int M;
struct Record {
	char id[18];
	int come,leave;
} first,last,tmp;

int main() {
	scanf("%d",&M);
	char id[18];
	int h1,m1,s1,h2,m2,s2;
	scanf("%s %d:%d:%d %d:%d:%d",tmp.id,&h1,&m1,&s1,&h2,&m2,&s2);
	tmp.come = h1 * 3600 + m1 * 60 + s1;
	tmp.leave = h2 * 3600 + m2 * 60 + s2;
	strcpy(first.id,tmp.id);
	strcpy(last.id,tmp.id);
	first.come = tmp.come;
	last.leave = tmp.leave;

	for(int i = 1; i < M; i ++) {
		scanf("%s %d:%d:%d %d:%d:%d",tmp.id,&h1,&m1,&s1,&h2,&m2,&s2);
		tmp.come = h1 * 3600 + m1 * 60 + s1;
		tmp.leave = h2 * 3600 + m2 * 60 + s2;
		if(tmp.come < first.come) {
			strcpy(first.id,tmp.id);
			first.come = tmp.come;
		}
		if(tmp.leave > last.leave) {
			strcpy(last.id,tmp.id);
			last.leave = tmp.leave;
		}
	}
	printf("%s %s",first.id,last.id);
	return 0;
}
