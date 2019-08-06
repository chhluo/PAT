#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXK 101
int N,K;
struct Customer {
	int come,process;
	Customer() {}
	Customer(int cc,int pp):come(cc),process(pp) {}
};
bool cmp(Customer & X,Customer & Y) {
	return X.come < Y.come;
}
vector <Customer> V;
int wdw[MAXK];
int main() {
	int h,m,s,p,t;
	scanf("%d%d",&N,&K);
	for(int i = 0; i < N; i ++) {
		scanf("%d:%d:%d %d",&h,&m,&s,&p);
		t = h * 3600 + m * 60 + s;
		if(t <= 17 * 3600)
			V.push_back(Customer(t,p * 60));
	}
	sort(V.begin(),V.end(),cmp);
	N = V.size();
	double wT = 0.0;
	int idx;
	fill(wdw,wdw + K,8 * 3600);
	for(auto it = V.begin(); it != V.end(); it ++) {
		idx = min_element(wdw,wdw + K) - wdw;
		if(wdw[idx] > it->come) {
			wT += wdw[idx] - it->come;
			if(it->process > 3600)
				wdw[idx] += 3600;
			else
				wdw[idx] += it->process;
		} else {
			if(it->process > 3600)
				wdw[idx] = it->come + 3600;
			else
				wdw[idx] = it->come + it->process;
		}
	}
	printf("%.1lf",wT / 60 / N);
	return 0;
}
