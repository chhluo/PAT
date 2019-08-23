#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define MAX 100000
int N,S[MAX];
set <int> ALLID;
struct Node {
	set <int> st;
	double sets,area;
};
typedef map <int,Node> MP;
MP mp;
struct TMP {
	int id;
	double m,area;
	TMP(int ii,double mm,double aa):id(ii),m(mm),area(aa) {}
};
vector <TMP> tmp;
struct ANS {
	int id,n;
	double avgSets,avgArea;
	bool operator < (ANS & X) {
		if(this->avgArea != X.avgArea)
			return this->avgArea > X.avgArea;
		else
			return this->id < X.id;
	}
	ANS(int ii,int nn,double asets,double aarea):id(ii),n(nn),avgSets(asets),avgArea(aarea) {}
};
void init() {
	for(int i = 0; i < MAX; i ++)
		S[i] = -1;
}
int Find(int S[],int x) {
	if(S[x] == -1) 	return x;
	else return S[x] = Find(S,S[x]);
}
void Union(int S[],int r1,int r2) {
	S[r1] = r2;
}
int main() {
	init();
	scanf("%d",&N);
	int id,fid,mid,cid,K;
	double m,area;
	int r1,r2;
	for(int i = 0; i < N; i ++) {
		scanf("%d%d%d%d",&id,&fid,&mid,&K);
		ALLID.insert(id);
		if(fid != -1) {
			ALLID.insert(fid);
			r1 = Find(S,id);
			r2 = Find(S,fid);
			if(r1 != r2)	Union(S,r1,r2);
		}
		if(mid != -1) {
			ALLID.insert(mid);
			r1 = Find(S,id);
			r2 = Find(S,mid);
			if(r1 != r2)	Union(S,r1,r2);
		}
		for(int j = 0; j < K; j ++) {
			scanf("%d",&cid);
			ALLID.insert(cid);
			r1 = Find(S,id);
			r2 = Find(S,cid);
			if(r1 != r2)	Union(S,r1,r2);
		}
		scanf("%lf%lf",&m,&area);
		tmp.push_back(TMP(id,m,area));
	}
	MP::iterator mpit;
	for(auto it = ALLID.begin(); it != ALLID.end(); it ++) {
		int r = Find(S,*it);
		mpit = mp.find(r);
		if(mpit == mp.end()) {
			mp[r].area = 0.0;
			mp[r].sets = 0.0;
		}
		mp[r].st.insert(*it);
	}
	for(auto it = tmp.begin(); it != tmp.end(); it ++) {
		int r = Find(S,it->id);
		mp[r].area += it->area;
		mp[r].sets += it->m;
	}
	vector <ANS> ans;
	for(auto it = mp.begin(); it != mp.end(); it ++)
		ans.push_back(ANS(*(it->second.st.begin()),it->second.st.size(),it->second.sets / it->second.st.size(),it->second.area / it->second.st.size()));
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(auto it = ans.begin(); it != ans.end(); it ++)
		printf("%04d %d %.3lf %.3lf\n",it->id,it->n,it->avgSets,it->avgArea);
	return 0;
}
