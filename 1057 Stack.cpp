#include <iostream>
#include <set>
#include <stack>
#include <functional>
using namespace std;
int N;
int main() {
	//freopen("in.txt","r",stdin);
	stack <int> S;
	multiset <int,greater <int>> left;
	multiset <int> right;
	scanf("%d",&N);
	char s[20];
	int key;
	for(int i = 0; i < N; i ++) {
		scanf("%s",s);
		if(s[1] == 'u') {
			scanf("%d",&key);
			S.push(key);
			if(left.size() != 0 && *left.begin() <= key)
				right.insert(key);
			else
				left.insert(key);
		} else {
			if(S.size() == 0)
				printf("Invalid\n");
			else {
				if(s[1] == 'o') {
					key = S.top();
					S.pop();
					printf("%d\n",key);
					auto it = left.find(key);
					if(it != left.end())
						left.erase(it);
					else {
						it = right.find(key);
						right.erase(it);
					}
				} else {
					key = *left.begin();
					printf("%d\n",key);
				}
			}
		}
		while(left.size() < right.size()) {
			left.insert(*right.begin());
			right.erase(right.begin());
		}
		while(left.size() > right.size() + 1) {
			right.insert(*left.begin());
			left.erase(left.begin());
		}
	}
	return 0;
}

