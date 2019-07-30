#include <cstdio>
#include <algorithm>
using namespace std;
int N,D;
struct MoonCake{
	double mount,prices,perTon;
};
MoonCake cakes[1010];
bool cmp(MoonCake & X, MoonCake & Y){
	return X.perTon > Y.perTon;
}
int main(){
	scanf("%d%d",&N,&D);
	for(int i = 0;i < N;i ++)
		scanf("%lf",&cakes[i].mount);
	for(int i = 0;i < N;i ++){
		scanf("%lf",&cakes[i].prices);
		cakes[i].perTon = cakes[i].prices / cakes[i].mount;
	}
	sort(cakes,cakes + N,cmp);
	double profit = 0;
	for(int i = 0;i < N;i ++){
		if(D == 0)
			break;
		if(cakes[i].mount <= D){
			profit += cakes[i].prices;
			D -= cakes[i].mount;
		}else{
			profit += cakes[i].perTon * D;
			D = 0;
		}
	}
	printf("%.2lf",profit);
	return 0;
}