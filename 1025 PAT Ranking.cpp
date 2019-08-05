#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAXN 101
int N,K,total = 0;
struct Testee {
	long long int id;
	int location,score,finalRank,localRank;
	Testee(long long int id_,int ll,int ss):id(id_),location(ll),score(ss) {	}
};

vector <Testee *> place[MAXN];
vector <Testee *> ans;
bool cmp(const Testee * X,const Testee * Y) {
	if(X->score != Y->score)
		return X->score > Y->score;
	else
		return X->id < Y->id;
}

int main() {
	scanf("%d",&N);
	int s;
	long long int id;
	for(int i = 1; i <= N; i ++) {
		scanf("%d",&K);
		total += K;
		for(int j = 0; j < K; j ++) {
			scanf("%lld %d",&id,&s);
			place[i].push_back(new Testee(id,i,s));
		}
		sort(place[i].begin(),place[i].end(),cmp);
		place[i][0]->localRank = 1;
		for(unsigned int j = 1; j < place[i].size(); j ++)
			place[i][j]->localRank = place[i][j]->score != place[i][j-1]->score ? j + 1 : place[i][j-1]->localRank;
		for(unsigned int j = 0; j < place[i].size(); j ++)
			ans.push_back(place[i][j]);
	}
	sort(ans.begin(),ans.end(),cmp);
	ans[0]->finalRank = 1;
	for(int i = 1; i < total; i ++)
		ans[i]->finalRank = ans[i]->score == ans[i-1]->score ? ans[i-1]->finalRank : i + 1;
	printf("%d\n",total);
	for(int i = 0 ; i < total; i ++)
		printf("%013lld %d %d %d\n",ans[i]->id,ans[i]->finalRank,ans[i]->location,ans[i]->localRank);
	return 0;
}
