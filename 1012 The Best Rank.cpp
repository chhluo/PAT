#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 2010
int N,M;
char symbol[5] = "ACME";
struct Student {
	int id;
	int score[4],rank[4];
};
vector <Student*> stu;
typedef Student * ps;
map <int,int> nameList;
map<int,int>::iterator it;
bool cmpA(const ps X,const ps Y) {
	return X->score[0] > Y->score[0];
}
bool cmpC(const ps X,const ps Y) {
	return X->score[1] > Y->score[1];
}
bool cmpM(const ps X,const ps Y) {
	return X->score[2] > Y->score[2];
}
bool cmpE(const ps X,const ps Y) {
	return X->score[3] > Y->score[3];
}
void writeRank(int num) {
	stu[0]->rank[num] = 1;
	for(unsigned int i = 1; i < stu.size(); i ++)
		if(stu[i - 1]->score[num] == stu[i]->score[num])
			stu[i]->rank[num] = stu[i - 1]->rank[num];
		else
			stu[i]->rank[num] = i + 1;
}

int main() {
	scanf("%d%d",&N,&M);
	int id,c,m,e;
	for(int i = 0; i < N; i ++) {
		scanf("%d%d%d%d",&id,&c,&m,&e);
		stu.push_back(new Student());
		stu[i]->id = id;
		stu[i]->score[0] = c + m + e;
		stu[i]->score[1] = c;
		stu[i]->score[2] = m;
		stu[i]->score[3] = e;
	}
	sort(stu.begin(),stu.end(),cmpA);
	writeRank(0);
	sort(stu.begin(),stu.end(),cmpC);
	writeRank(1);
	sort(stu.begin(),stu.end(),cmpM);
	writeRank(2);
	sort(stu.begin(),stu.end(),cmpE);
	writeRank(3);
	for(unsigned int i = 0; i < stu.size(); i ++)
		nameList[stu[i]->id] = i;

	for(int i = 0; i < M; i ++) {
		scanf("%d",&id);
		it = nameList.find(id);
		if(it == nameList.end()) {
			printf("N/A\n");
		} else {
			int bst = min_element(stu[it->second]->rank,stu[it->second]->rank + 4) - stu[it->second]->rank;
			printf("%d %C\n",stu[it->second]->rank[bst],symbol[bst]);
		}
	}
	return 0;
}
