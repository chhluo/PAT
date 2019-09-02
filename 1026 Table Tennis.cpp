#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define OPENTIME 8 * 3600
#define CLOSETIME 21 * 3600
#define MAXM 101
int N,M,K;
//还有一个测试点没过 
struct Table {
	int id,endServe;
	bool vip;
	Table() {}
	Table(int id_,int endServe_,bool vip_):id(id_),endServe(endServe_),vip(vip_) {}
};
typedef struct Table * PtrToTable;
struct RuleForTable {
	bool operator () (const PtrToTable px, const PtrToTable py)const {
		return px->endServe != py->endServe ? (px->endServe < py->endServe):(px->id < py->id);
	}
};

typedef set<PtrToTable,RuleForTable> TableQueue;
TableQueue tableQ;
TableQueue::iterator Tit;

struct Player {
	int demand;
	int arriveTime,waitTime,serveTime;
	bool vip;
	Player() {}
	Player(int h_,int m_,int s_,int demand_,bool vp):
		demand(demand_ > 120 ? 7200 : demand_ * 60),vip(vp),arriveTime(h_ * 3600 + m_ * 60 + s_) {}
	bool operator < (Player X)const {
		return this->arriveTime < X.arriveTime;
	}
};
typedef set <Player> PlayerQueue;
PlayerQueue playerQ;
PlayerQueue::iterator Pit;
vector <Player> processed;

int cntServe[MAXM] = {0};
void FormateTime(int total,int &h,int &m,int &s) {
	h = total / 3600;
	m = (total - h * 3600) / 60;
	s = total % 60;
}

bool MinIdVipTableBeforePlayer(TableQueue & tableQ,int time,PtrToTable & PtrViptable) {
	TableQueue::iterator it,MinIdOne;
	TableQueue VipTableQ;
	for(it = tableQ.begin(); it != tableQ.end(); it ++) {
		if((*it)->endServe <= time && (*it)->vip) {
			VipTableQ.insert(*it);
		}
	}
	if(VipTableQ.size() == 0)
		return false;
	else {
		MinIdOne = VipTableQ.begin();
		for(it = VipTableQ.begin(); it != VipTableQ.end(); it ++) {
			if((*MinIdOne)->id > (*it)->id)
				MinIdOne = it;
		}
		PtrViptable = *MinIdOne;
		return true;
	}
}

bool MinIdTableBeforePlayer(TableQueue & tableQ,int time,PtrToTable & PtrTable,bool Vip) {
	TableQueue::iterator it,MinIdOne;
	TableQueue TmpTableQ;
	if(Vip) { //just serach non-vip tables
		for(it = tableQ.begin(); it != tableQ.end(); it ++) {
			if((*it)->endServe <= time && !(*it)->vip) {
				TmpTableQ.insert(*it);
			}
		}
	} else { //search all tables
		for(it = tableQ.begin(); it != tableQ.end(); it ++) {
			if((*it)->endServe <= time) {
				TmpTableQ.insert(*it);
			}
		}
	}
	if(TmpTableQ.size() == 0) {
		return false;
	} else {
		MinIdOne = TmpTableQ.begin();
		for(it = TmpTableQ.begin(); it != TmpTableQ.end(); it ++) {
			if((*MinIdOne)->id > (*it)->id)
				MinIdOne = it;
		}
		PtrTable = *MinIdOne;
		return true;
	}
}

bool VipPlayerAfterVipTable(PlayerQueue & playerQ,int time,PlayerQueue::iterator & Pit) {
	PlayerQueue::iterator it;
	for(it = playerQ.begin(); it != playerQ.end() && it->arriveTime <= time; it ++) {
		if(it->vip)
			break;
	}
	if(it == playerQ.end() || it->arriveTime > time)
		return false;
	else {
		Pit = it;
		return true;
	}
}

void OutputAns() {
	int h1,h2,m1,m2,s1,s2;
	for(unsigned int i = 0; i < processed.size(); i ++) {
		FormateTime(processed[i].arriveTime,h1,m1,s1);
		FormateTime(processed[i].serveTime,h2,m2,s2);
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",h1,m1,s1,h2,m2,s2,(int) round(processed[i].waitTime / 60.0));
	}
	for(int i = 1; i <= K; i ++)
		printf("%d%c",cntServe[i],i < K ?' ':'\n');
}
int main() {
	//freopen("in.txt","r",stdin);
	scanf("%d",&N);
	int h,m,s,d,v;
	for(int i = 0; i < N; i ++) {
		scanf("%d:%d:%d %d %d",&h,&m,&s,&d,&v);
		playerQ.insert(Player(h,m,s,d,v == 1));
	}
	scanf("%d%d",&K,&M);
	set <int> VipTableId;
	int id;
	for(int i = 0; i < M; i ++) {
		scanf("%d",&id);
		VipTableId.insert(id);
	}
	for(int i = 1; i <= K; i ++)
		tableQ.insert(new Table(i,OPENTIME,VipTableId.find(i) != VipTableId.end()));

	while(!playerQ.empty()) {
		Tit = tableQ.begin();
		Pit = playerQ.begin();
		if((*Tit)->endServe >= CLOSETIME)
			break;
		PtrToTable PtrTable;
		Player tmpPlayer;
		if(Pit->arriveTime >= (*Tit)->endServe) {
			//all players come after the eariest table's endserve time
			if(Pit->vip) { //the player is a vip
				//check the existence of a vip table whose endserve time is before the player come
				bool flag = MinIdVipTableBeforePlayer(tableQ,Pit->arriveTime,PtrTable);
				if(!flag)//if can not find a vip table,find a normal one
					MinIdTableBeforePlayer(tableQ,Pit->arriveTime,PtrTable,Pit->vip);
			} else { //player is a normal one,not a vip
				MinIdTableBeforePlayer(tableQ,Pit->arriveTime,PtrTable,Pit->vip);
			}

			tableQ.erase(PtrTable);
			cntServe[PtrTable->id] ++;
			tmpPlayer = *Pit;
			playerQ.erase(Pit);
			tmpPlayer.waitTime = 0;
			tmpPlayer.serveTime = tmpPlayer.arriveTime;
			processed.push_back(tmpPlayer);

			PtrTable->endServe = min(CLOSETIME,tmpPlayer.serveTime + tmpPlayer.demand);
			tableQ.insert(PtrTable);
		} else { //some players came before or preciesely at the table's endserve time
			PtrTable = *Tit;
			tableQ.erase(PtrTable);
			/*
			printf("show queue\n");
			for(TableQueue::iterator it = tableQ.begin();it != tableQ.end(); it ++){
			FormateTime((*it)->endServe,h,m,s);
			printf("id = %d endtime = %02d:%02d:%02d\n",(*it)->id,h,m,s);
			}
			printf("end list\n\n");
			*/
			if(PtrTable->vip) { // a vip table
				bool flag = VipPlayerAfterVipTable(playerQ,PtrTable->endServe,Pit);
				if(!flag) { //can not find a vip player,just find a normal one
					Pit = playerQ.begin();
				}
			} else { //not a vip table
				Pit = playerQ.begin();
			}

			tmpPlayer = *Pit;
			playerQ.erase(Pit);
			tmpPlayer.serveTime = PtrTable->endServe;
			tmpPlayer.waitTime = tmpPlayer.serveTime - tmpPlayer.arriveTime;
			processed.push_back(tmpPlayer);
			cntServe[PtrTable->id] ++;

			PtrTable->endServe = min(CLOSETIME,tmpPlayer.serveTime + tmpPlayer.demand);
			tableQ.insert(PtrTable);
		}
	}
	OutputAns();
	return 0;
}
