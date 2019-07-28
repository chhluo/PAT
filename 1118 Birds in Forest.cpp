#include <cstdio>
#include <set>
using namespace std;
#define MAX 10010
int N,K,Q;
int S[MAX];
set <int> birds;
void Init(){
	for(int i = 0;i < MAX;i ++)
		S[i] = -1;
}

int Find(int x){
	if(S[x] == -1)
		return x;
	else
		return S[x] = Find(S[x]);
}

void Union(int x1,int x2){
	S[x1] = x2;
}

int main(){
	Init();
	scanf("%d",&N);
	int idx1,idx2;
	int r1,r2;
	for(int i = 0;i < N;i ++){
		scanf("%d",&K);
		if(K > 0){
			scanf("%d",&idx1);
			birds.insert(idx1);
		}
		for(int j = 1;j < K;j ++){
			scanf("%d",&idx2);
			birds.insert(idx2);
			r1 = Find(idx1);
			r2 = Find(idx2);
			if(r1 != r2)
				Union(r1,r2);
		}
	}
	int cntBirds = birds.size();
	int cntTree = 0;
	for(int i = 1;i <= cntBirds;i ++)
		cntTree += S[i] == -1;
	printf("%d %d\n",cntTree,cntBirds);
	scanf("%d",&Q);
	for(int i = 0;i < Q;i ++){
		scanf("%d%d",&idx1,&idx2);
		r1 = Find(idx1);
		r2 = Find(idx2);
		printf("%s\n",r1 == r2 ? "Yes":"No");
	}
	return 0;
}