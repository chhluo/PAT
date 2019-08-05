#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int N,C;
struct Record {
	int id,grade;
	char name[10];
	Record(int ii, int gg,char nn[]):id(ii),grade(gg) {
		strcpy(name,nn);
	}
};
typedef Record * PtrToR;
vector <PtrToR> ans;
bool cmp1(const PtrToR X,const PtrToR Y) {
	return X->id < Y->id;
}
bool cmp2(const PtrToR X,const PtrToR Y) {
	if(strcmp(X->name,Y->name) != 0)
		return strcmp(X->name,Y->name) < 0;
	else
		return X->id < Y->id;
}
bool cmp3(const PtrToR X,const PtrToR Y) {
	if(X->grade != Y->grade)
		return X->grade < Y->grade;
	return X->id < Y->id;
}
int main() {
	scanf("%d%d",&N,&C);
	int id,grade;
	char name[10];
	for(int i = 0; i < N; i ++) {
		scanf("%d %s %d",&id,name,&grade);
		ans.push_back(new Record(id,grade,name));
	}
	switch (C) {
		case 1:
			sort(ans.begin(),ans.end(),cmp1);
			break;
		case 2:
			sort(ans.begin(),ans.end(),cmp2);
			break;
		default:
			sort(ans.begin(),ans.end(),cmp3);
			break;
	}
	for(int i = 0; i < N; i ++)
		printf("%06d %s %d\n",ans[i]->id,ans[i]->name,ans[i]->grade);
	return 0;
}
