#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 100010
int N,gMin,gMax;
struct Node {
	int grade;
	string name,id;
	Node(string nn,string ii,int gg):name(nn),id(ii),grade(gg) {}
};
typedef Node * PtrToN;
vector <PtrToN> tmp[101],ans;
bool cmp(PtrToN X,PtrToN Y) {
	return X->grade > Y->grade;
}
int main() {
	scanf("%d",&N);
	char name[20],id[20];
	int gg;
	for(int i = 0; i < N; i ++) {
		scanf("%s %s %d",name,id,&gg);
		tmp[gg].push_back(new Node(name,id,gg));
	}
	scanf("%d%d",&gMin,&gMax);
	for(int i = gMin; i <= gMax; i ++) {
		for(auto it = tmp[i].begin(); it != tmp[i].end(); it ++)
			ans.push_back(*it);
	}
	sort(ans.begin(),ans.end(),cmp);
	if(ans.size() == 0)
		printf("NONE");
	else {
		for(auto it = ans.begin(); it != ans.end(); it ++)
			printf("%s %s\n",(*it)->name.c_str(),(*it)->id.c_str());
	}
	return 0;
}
