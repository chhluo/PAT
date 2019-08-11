#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Person {
	int id,vs,ts,ss,type;
	Person(int ii,int vv,int tt,int ss_,int type_):id(ii),vs(vv),ts(tt),ss(ss_),type(type_) {}
};
typedef struct Person * PtrToP;
int N,H,L;
vector <PtrToP> ans;
bool cmp(const PtrToP X,const PtrToP Y) {
	if(X->type != Y->type) 	return X->type < Y->type;
	else if(X->ss != Y->ss) return X->ss > Y->ss;
	else if(X->vs != Y->vs) return X->vs > Y->vs;
	else return X->id < Y->id;
}
int main() {
	scanf("%d%d%d",&N,&L,&H);
	int id,vs,ts,ss,type;
	PtrToP p;
	for(int i = 0; i < N; i ++) {
		scanf("%d%d%d",&id,&vs,&ts);
		if(vs >= L && ts >= L) {
			ss = ts + vs;
			if(vs >= H && ts >= H) type = 1;
			else if(vs >= H) type = 2;
			else if(vs >= ts) type = 3;
			else type = 4;
			p = new Person(id,vs,ts,ss,type);
			ans.push_back(p);
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	printf("%d\n",ans.size());
	for(unsigned int i = 0; i < ans.size(); i ++)
		printf("%08d %d %d\n",ans[i]->id,ans[i]->vs,ans[i]->ts);
	return 0;
}
