#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
int N,M;
struct Tester {
	string id;
	int score;
	Tester(string ii,int ss):id(ii),score(ss) {}
};
typedef struct Tester* PtrToT;
bool cmp(PtrToT x,PtrToT y) {
	return x->score != y->score ? x->score > y->score : x->id < y->id;
}
vector <PtrToT> Level[3];
typedef vector <PtrToT>::iterator LIT;

struct Type2 {
	int nt,ns;
	Type2():nt(0),ns(0) {}
};
Type2 T2[1001];

struct Type3 {
	int sid,nt;
	Type3(int ss,int nn):sid(ss),nt(nn) {}
	bool operator < (Type3 x) const {
		return this->nt != x.nt ? this->nt > x.nt : this->sid < x.sid;
	}
};
set <Type3> T3;
typedef map <int,vector<PtrToT>> MP;
MP mp;
map <int,int> table;

int getSite(string s) {
	return stoi(s.substr(1,3));
}
int getDate(string s) {
	return stoi(s.substr(4,6));
}
int main() {
	scanf("%d%d",&N,&M);
	char id[20];
	int score;
	for(int i = 0; i < N; i ++) {
		scanf("%s %d\n",id,&score);
		PtrToT p = new Tester(id,score);
		switch (id[0]) {
			case 'A':
				Level[0].push_back(p);
				break;
			case 'B':
				Level[1].push_back(p);
				break;
			default:
				Level[2].push_back(p);
				break;
		}
		int sid = getSite(p->id);
		T2[sid].nt ++;
		T2[sid].ns += score;
		mp[getDate(p->id)].push_back(p);
	}
	for(int i = 0; i < 3; i ++)
		sort(Level[i].begin(),Level[i].end(),cmp);
	string query;
	LIT its,ite;
	int sid;
	for(int i = 1; i <= M; i ++) {
		getline(cin,query);
		printf("Case %d: %s\n",i,query.c_str());
		switch (query[0]) {
			case '1':
				if(query[2] == 'A') {
					its = Level[0].begin();
					ite = Level[0].end();
				} else if(query[2] == 'B') {
					its = Level[1].begin();
					ite = Level[1].end();
				} else {
					its = Level[2].begin();
					ite = Level[2].end();
				}
				if(its == ite) printf("NA\n");
				else {
					while(its != ite) {
						printf("%s %d\n",(*its)->id.c_str(),(*its)->score);
						its ++;
					}
				}
				break;
			case '2':
				sid = stoi(query.substr(2));
				if(sid < 100 || sid > 999 || T2[sid].nt == 0) printf("NA\n");
				else printf("%d %d\n",T2[sid].nt,T2[sid].ns);
				break;
			case '3':
				int date = stoi(query.substr(2));
				MP::iterator dit = mp.find(date);
				if(dit == mp.end() || dit->second.size() == 0) printf("NA\n");
				else {
					for(auto it = dit->second.begin(); it != dit->second.end(); it ++) {
						sid = getSite((*it)->id);
						if(table.find(sid) == table.end())
							table[sid] = 1;
						else
							table[sid] ++;
					}
					for(auto it = table.begin(); it != table.end(); it ++)
						T3.insert(Type3(it->first,it->second));
					for(auto it = T3.begin(); it != T3.end(); it ++)
						printf("%d %d\n",it->sid,it->nt);
					T3.clear();
					table.clear();
				}
				break;
		}
	}
	return 0;
}
