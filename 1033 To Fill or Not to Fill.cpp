#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-10;
double Cmax,D,Davg;
int N;
struct Station{
	double price,dis;
}sta[510];
bool cmp(Station & X,Station & Y){
	return X.dis < Y.dis;
}
int main(){
	scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&N);
	for(int i = 0 ;i < N;i ++)
		scanf("%lf%lf",&sta[i].price,&sta[i].dis);
	sort(sta,sta + N,cmp);
	sta[N].dis = D;//如果最后的加油站不是终点，就添加上去，即使是，这样添加也不会影响结果
	sta[N].price = 0;
	
	double CurPos = 0,tank = 0,TotalPrice = 0, Maxrange = Cmax * Davg, tankRange = 0;
	int idx;
	if(fabs(sta[0].dis) < eps){//第一个加油站不是起点
		for(int i = 0;i < N;){
			tankRange = tank * Davg;
			idx = i;
			for(int j = i + 1;j <= N;j ++)
				if(CurPos + tankRange >= sta[j].dis && sta[j].price < sta[idx].price)
					idx = j;
			if(idx != i){//有可以不加油就能到达的价格更便宜加油站
                tank -= (sta[idx].dis - CurPos) / Davg;
                CurPos = sta[idx].dis;            
				i = idx;
			}else{//没有可以不加油就能到达的价格更便宜的加油站
				for(int j = i + 1;j <= N;j ++)
					if(CurPos + Maxrange >= sta[j].dis && sta[j].price <= sta[i].price){
						idx = j;
						break;
					}
					if(idx != i){//有加点油就能到达的价格相等或者更便宜的加油站
						TotalPrice += ((sta[idx].dis - sta[i].dis) / Davg - tank) * sta[i].price;
						tank = 0;
						CurPos = sta[idx].dis;
						i = idx;
					}else{//在满油范围内没有价格相等或者更便宜的加油站
						if(CurPos + Maxrange < sta[i + 1].dis){
							//满油范围内没有加油站
							TotalPrice += (Cmax - tank) * sta[i].price;
							CurPos += Maxrange;
							break;
						}else{//满油范围内只有更贵的加油站
							if(i == N - 1){//下一站就是终点，则不需要加满
								TotalPrice += ((sta[i + 1].dis - CurPos) / Davg - tank) * sta[i].price;
								CurPos = sta[i + 1].dis;
								tank = 0;
								i ++;
							}else{//加满油开到满油范围内最便宜的加油站
								idx = i + 1;
								for(int j = i + 1;j <= N;j ++)
									if(CurPos + Maxrange >= sta[j].dis && sta[j].price < sta[idx].price)
										idx = j;
								TotalPrice += (Cmax - tank) * sta[i].price;
								tank = Cmax;
								tank -= (sta[idx].dis - CurPos) / Davg;
								CurPos = sta[idx].dis;
								i = idx;
							}
						}
					}
			}
		}
	}
	if(CurPos == D)
		printf("%.2lf",TotalPrice);
	else
		printf("The maximum travel dis = %.2f",CurPos);
	return 0;
}