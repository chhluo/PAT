#include <cstdio>
#include <vector>
using namespace std;
#define MAXN 101
int N,M,K;
int cntLeaves[MAXN] = {0};
vector <int> T[MAXN];
int ans[MAXN] = {0};
int MaxLevel;
struct Node {
	int id,level;
	Node() {}
	Node(int id_,int level_):id(id_),level(level_) {}
};
void LevelOrder() {
	Node Q[MAXN];
	int head = 0, rear = 0;
	Q[rear ++] = Node(1,1);
	MaxLevel = 1;
	Node top;
	while(head < rear) {
		top = Q[head ++];
		MaxLevel = max(MaxLevel,top.level);
		for(unsigned int i = 0; i < T[top.id].size(); i ++) {
			Q[rear ++] = Node(T[top.id][i],top.level + 1);
		}
	}
	for(head = 0; head < rear; head ++)
		ans[Q[head].level] += T[Q[head].id].size() == 0;
}

int main() {
	scanf("%d%d",&N,&M);
	int id,child;
	for(int i = 0; i < M; i ++) {
		scanf("%d%d",&id,&K);
		for(int j = 0; j < K; j ++) {
			scanf("%d",&child);
			T[id].push_back(child);
		}
	}
	LevelOrder();
	for(int i = 1; i <= MaxLevel; i ++)
		printf("%d%c",ans[i],i < MaxLevel ? ' ':'\n');

	return 0;
}
