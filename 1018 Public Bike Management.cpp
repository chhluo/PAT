#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAXN 510
#define INF 0x3f3f3f3f
int Cmax,N,Sp,M,Half;
int Station[MAXN],MinLen,Len,MinBikeTake,BikeTake,MinBikeSend,BikeSend;
bool vis[MAXN] = {false};
struct Road{
	int next,len;
	Road(int nn,int ll):next(nn),len(ll){}
};
vector <Road> G[MAXN];
vector <int> Path,MinPath;
void Input(){
	scanf("%d%d%d%d",&Cmax,&N,&Sp,&M);
	for(int i = 1;i <= N;i ++)
		scanf("%d",Station + i);
	int v1,v2,len;
	for(int i = 0;i < M;i ++){
		scanf("%d%d%d",&v1,&v2,&len);
		G[v1].push_back(Road(v2,len));
		G[v2].push_back(Road(v1,len));
	}
}

void dfs(int S){
	if(S == Sp){
		if(Len < MinLen){
			MinLen = Len;
			MinBikeTake = BikeTake;
			MinBikeSend = BikeSend;
			MinPath = Path;
		}else if(Len == MinLen && ((BikeSend < MinBikeSend) || (BikeSend == MinBikeSend && BikeTake < MinBikeTake))){
			MinBikeSend = BikeSend;
			MinBikeTake = BikeTake;
			MinPath = Path;
		}
	}else{
		int next,tmp;
		for(unsigned int i = 0;i < G[S].size();i ++){
			next = G[S][i].next;
			if(vis[next] || Len + G[S][i].len > MinLen)
				continue;
			vis[next] = true;
			Len += G[S][i].len;
			Path.push_back(next);
			tmp = Station[next] - Half;
			int tmpBikeTake = BikeTake,tmpBikeSend = BikeSend;
			if(tmp >= 0){
				BikeTake += tmp;
			}else{//少自行车 tmp < 0
				if(BikeTake > 0){//如果一开始就遇到少自行车的情况，那么一开始就必须从起点带自行车
					BikeTake += tmp;
					if(BikeTake < 0){
						BikeSend -= BikeTake;
						BikeTake = 0;
					}
				}else
					BikeSend -= tmp;
			}
			dfs(next);
			vis[next] = false;
			Len -= G[S][i].len;
			Path.pop_back();
			BikeSend = tmpBikeSend;
			BikeTake = tmpBikeTake;
		}
	}
}
int main(){
	Input();
	Half = Cmax / 2;
	MinLen = MinBikeTake = MinBikeSend = INF;
	Len = BikeTake = BikeSend = 0;
	vis[0] = true;
	Path.push_back(0);
	dfs(0);
	printf("%d ",MinBikeSend);
	printf("%d",MinPath[0]);
	for(unsigned int i = 1;i < MinPath.size();i ++)
		printf("->%d",MinPath[i]);
	printf(" %d",MinBikeTake);
	return 0;
}