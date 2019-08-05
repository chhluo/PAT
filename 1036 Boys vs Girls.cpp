#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
struct P {
	char name[12],id[12];
	int grade;
	P(char nn[],char ii[],int gg):grade(gg) {
		strcpy(name,nn);
		strcpy(id,ii);
	}
};
typedef P* PtrToP;
vector <PtrToP> male,female;

bool cmp(PtrToP X,PtrToP Y) {
	return X->grade > Y->grade;
}
int main() {
	int n,grade;
	char name[12],id[12],gender;
	scanf("%d",&n);
	for(int i = 0; i < n; i ++) {
		scanf("%s %c %s %d",name,&gender,id,&grade);
		if(gender == 'M')
			male.push_back(new P(name,id,grade));
		else
			female.push_back(new P(name,id,grade));
	}
	auto m = max_element(male.begin(),male.end(),cmp);
	auto f = min_element(female.begin(),female.end(),cmp);
	if(f == female.end())
		printf("Absent\n");
	else
		printf("%s %s\n",(*f)->name,(*f)->id);
	if(m == male.end())
		printf("Absent\n");
	else
		printf("%s %s\n",(*m)->name,(*m)->id);
	if(f == female.end() || m == male.end())
		printf("NA");
	else
		printf("%d",(*f)->grade - (*m)->grade);
	return 0;
}
