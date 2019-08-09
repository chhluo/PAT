#include <iostream>
#include <map>
using namespace std;
int img[801][601],N,M;
map <int,int> color;
int main() {
	scanf("%d%d",&N,&M);
	for(int i = 0; i < N; i ++)
		for(int j = 0; j < M; j ++) {
			scanf("%d",&img[i][j]);
			color[img[i][j]] ++;
		}
	int Max ,fre = 0;
	for(auto it = color.begin(); it != color.end(); it ++)
		if(it->second > fre) {
			fre = it->second;
			Max = it->first;
		}
	printf("%d",Max);
	return 0;
}

