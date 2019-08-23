#include <iostream>
#include <cmath>
#include <map>
#define MAXN 10010
using namespace std;
int N,K;
typedef enum {Mystery,Minion,Chocolate} AwardType;
struct S {
	bool checked;
	AwardType ward;
	S(bool cc,AwardType aa):checked(cc),ward(aa) {}
};
typedef map <int,S> MP;
MP mp;
bool Prime(int x) {
	if(x == 1)	return false;
	else if(x == 2)	return true;
	else {
		int r = sqrt(x);
		for(int i = 2; i <= r ; i ++)
			if(x % i == 0)
				return false;
		return true;
	}
}
int main() {
	scanf("%d",&N);
	int id;
	for(int i = 1; i <= N; i ++) {
		scanf("%d",&id);
		if(i == 1) {
			mp.insert(make_pair(id,S(false,Mystery)));
		} else {
			mp.insert(make_pair(id,S(false,Prime(i) ? Minion : Chocolate)));
		}
	}
	scanf("%d",&K);
	for(int i = 0; i < K; i ++) {
		scanf("%d",&id);
		auto it = mp.find(id);
		printf("%04d: ",id);
		if(it == mp.end())
			printf("Are you kidding?\n");
		else if(it->second.checked) {
			printf("Checked\n");
		} else {
			it->second.checked = true;
			switch (it->second.ward) {
				case Mystery:
					printf("Mystery Award\n");
					break;
				case Minion:
					printf("Minion\n");
					break;
				default:
					printf("Chocolate\n");
					break;
			}
		}
	}
	return 0;
}
