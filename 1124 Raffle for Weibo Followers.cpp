#include <iostream>
#include <string>
#include <set>
using namespace std;
int M,N,S;
string follower[1010];
set <string> winner;
int main() {
	scanf("%d%d%d",&M,&N,&S);
	for(int i = 1; i <= M; i ++)
		cin >> follower[i];
	while(S <= M) {
		if(winner.find(follower[S]) != winner.end()) {
			S += 1;
		} else {
			winner.insert(follower[S]);
			cout << follower[S] << endl;
			S += N;
		}
	}
	if(winner.size() == 0) 	printf("Keep going...");
	return 0;
}
