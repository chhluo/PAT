#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
int N,K;
map <string,set <int> > CourseList;
int main() {
	scanf("%d%d",&N,&K);
	int id,m;
	char name[6];
	for(int i = 0; i < K; i ++) {
		scanf("%d%d",&id,&m);
		for(int j = 0; j < m; j ++) {
			scanf("%s",name);
			CourseList[name].insert(id);
		}
	}
	for(int i = 0; i < N; i ++) {
		scanf("%s",name);
		printf("%s %d",name,CourseList[name].size());
		auto end = CourseList[name].end();
		for(auto it = CourseList[name].begin(); it != end; it ++)
			printf(" %d",*it);
		printf("\n");
	}
	return 0;
}
