#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
using namespace std;
int N,K;
int S[1001];
set <int> hobbies;
vector <int> h;
vector <int> roots;
int table[1001] = {0};
void InitSet(){
	for(int i = 1;i < 1001;i ++)
		S[i] = -1;
}
int Find(int x){
	if(S[x] == -1)
		return x;
	else
		return S[x] = Find(S[x]);
}
void Union(int r1,int r2){
	S[r1] = r2;
}

int main(){
	InitSet();
	scanf("%d",&N);
	int h1,h2,r1,r2;
	for(int i = 0;i < N;i ++){
		scanf("%d:",&K);
		if(K > 0){
			scanf("%d",&h1);
			hobbies.insert(h1);
			h.push_back(h1);
		}
		for(int j = 1 ;j < K; j ++){
			scanf("%d",&h2);
			hobbies.insert(h2);
			r1 = Find(h1);
			r2 = Find(h2);
			if(r1 != r2)
				Union(r1,r2);
		}
	}
	for(set<int>::iterator it = hobbies.begin();it != hobbies.end();it ++)
		if(S[*it] == -1)
			roots.push_back(*it);
	for(unsigned int i = 0;i < h.size();i ++)
		table[Find(h[i])] ++;
	vector <int> ans;
	for(unsigned int i = 0;i < roots.size();i ++)
		ans.push_back(table[roots[i]]);
	
	sort(ans.begin(),ans.end(),greater<int>());
	printf("%d\n",roots.size());
	for(unsigned int i = 0;i < ans.size();i ++)
		printf("%d%c",ans[i],i + 1 < ans.size() ? ' ':'\n');
	return 0;
}
