#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define MAXN 1000010
bool flag[10010] = {false};
int N;
struct Node {
	int ad,d,next;
};
Node A[MAXN],tmp;
vector <Node> ans1,ans2;
int main() {
	int head;
	scanf("%d %d",&head,&N);
	for(int i = 0; i < N; i ++) {
		scanf("%d%d%d",&tmp.ad,&tmp.d,&tmp.next);
		A[tmp.ad] = tmp;
	}
	int p = head;
	while(p != -1) {
		if(!flag[abs(A[p].d)]) {
			ans1.push_back(A[p]);
			flag[abs(A[p].d)] = true;
		} else
			ans2.push_back(A[p]);
		p = A[p].next;
	}
	for(unsigned int i = 0; i + 1 < ans1.size(); i ++)
		printf("%05d %d %05d\n",ans1[i].ad,ans1[i].d,ans1[i + 1].ad);
	if(ans1.size() > 0)
		printf("%05d %d -1\n",ans1.back().ad,ans1.back().d);
	for(unsigned int i = 0; i + 1 < ans2.size(); i ++)
		printf("%05d %d %05d\n",ans2[i].ad,ans2[i].d,ans2[i + 1].ad);
	if(ans2.size() > 0)
		printf("%05d %d -1\n",ans2.back().ad,ans2.back().d);
	return 0;
}
