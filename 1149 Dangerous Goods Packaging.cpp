#include <cstdio>
#include <set>
using namespace std;
int N,M,K;
struct Incompatible{
	int a,b;
}inc[10010];
set <int> goods;

int main(){
	scanf("%d%d",&N,&M);
	for(int i = 0;i < N;i ++)
		scanf("%d%d",&inc[i].a,&inc[i].b);
	
	int id;
	bool flag;
	for(int j = 0;j < M;j ++){
		scanf("%d",&K);
		for(int l = 0;l < K;l ++){
			scanf("%d",&id);
			goods.insert(id);
		}
		flag = true;
		for(int l = 0;l < N;l ++){
			if(goods.find(inc[l].a) != goods.end() && goods.find(inc[l].b) != goods.end()){
				flag = false;
				break;
			}
		}
		printf("%s\n",flag ? "Yes":"No");
		goods.clear();
	}

	return 0;
}