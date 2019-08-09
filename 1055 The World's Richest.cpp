#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define MAXN 100010
int N,K,M,Amin,Amax;
struct Bn {
	string name;
	int age,wealth;
	Bn(char nn[],int aa,int ww):name(nn),age(aa),wealth(ww) {}
};
typedef Bn *PtrToBn;
struct Rule {
	bool operator () (PtrToBn X,PtrToBn Y) {
		if(X->wealth != Y->wealth)
			return X->wealth > Y->wealth;
		else if(X->age != Y->age)
			return X->age < Y->age;
		else
			return X->name < Y->name;
	}
};
set <PtrToBn, Rule> bn[201];
vector <PtrToBn> tmp;
int main() {
	scanf("%d%d",&N,&K);
	char name[20];
	int age,wealth;
	PtrToBn p;
	for(int i = 0; i < N; i ++) {
		scanf("%s %d %d",name,&age,&wealth);
		p = new Bn(name,age,wealth);
		bn[age].insert(p);
	}
	for(int i = 1; i <= K; i ++) {
		scanf("%d%d%d",&M,&Amin,&Amax);
		tmp.clear();
		for(int j = 0; j < M; j ++) {
			int Max = -1;
			for(age = Amin; age <= Amax; age ++) {
				if(bn[age].size() > 0 && Max == -1) {
					Max = age;
				} else if(bn[age].size() > 0 && Rule()(*bn[age].begin(),*bn[Max].begin())) {
					Max = age;
				}
			}
			if(Max != -1) {
				tmp.push_back(*bn[Max].begin());
				bn[Max].erase(bn[Max].begin());
			}
		}
		printf("Case #%d:\n",i);
		if(tmp.size() == 0)
			printf("None\n");
		else {
			for(auto it = tmp.begin(); it != tmp.end(); it ++) {
				printf("%s %d %d\n",(*it)->name.c_str(),(*it)->age,(*it)->wealth);
				bn[(*it)->age].insert(*it);
			}
		}
	}
	return 0;
}
