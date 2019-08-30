#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define MAXN 10010
int N,K,row[MAXN];
string formation[MAXN];
struct P {
	string name;
	int height;
	bool operator < (P X)const {
		return this->height != X.height ? this->height > X.height:this->name < X.name;
	}
};
P p[MAXN];
int main() {
	scanf("%d%d",&N,&K);
	for(int i = 0; i < N; i ++)
		cin >> p[i].name >> p[i].height;
	sort(p,p + N);
	int m = N / K;
	for(int i = 0; i < K - 1; i ++)
		row[i] = m;
	row[K - 1] = N - (K - 1) * m;
	int pos = 0,e = 0;
	for(int i = K - 1; i >= 0; i --) {
		int center = row[i] / 2;
		e += row[i];
		formation[center] = p[pos ++].name;
		int cnt = 1;
		while(pos < e) {
			formation[center - cnt] = p[pos ++].name;
			if(pos < e)
				formation[center + cnt] = p[pos ++].name;
			cnt ++;
		}
		for(int j = 0; j < row[i]; j ++)
			printf("%s%c",formation[j].c_str(),j + 1 < row[i] ? ' ':'\n');
	}
	return 0;
}
