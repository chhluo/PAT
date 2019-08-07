#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define MAXK 2501
int N,K;
vector <string> StudentList[MAXK]; //会有同名学生，不能用set
int main() {
	scanf("%d%d",&N,&K);
	char name[6];
	int id,m;
	for(int i = 0; i < N; i ++) {
		scanf("%s %d",name,&m);
		for(int j = 0; j < m; j ++) {
			scanf("%d",&id);
			StudentList[id].push_back(name);
		}
	}
	for(int i = 1; i <= K; i ++) {
		printf("%d %d\n",i,StudentList[i].size());
		sort(StudentList[i].begin(),StudentList[i].end());
		for(auto it = StudentList[i].begin(); it != StudentList[i].end(); it ++)
			printf("%s\n",(*it).c_str());
	}
	return 0;
}
