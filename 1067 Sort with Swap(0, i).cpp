#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
#define MAXN 100010
int N,A[MAXN],idx[MAXN];
set <int> st;
int Find() {
	for(auto it = st.begin(); it != st.end(); it ++)
		if(idx[*it] != *it)
			return *it;
	return -1;
}
int main() {
	scanf("%d",&N);
	for(int i = 0; i < N; i ++) {
		scanf("%d",A + i);
		idx[A[i]] = i;
	}
	for(int i = 0; i < N; i ++)
		if(idx[i] != i)
			st.insert(i);
	int cnt = 0;
	while(1) {
		if(A[0] == 0) {
			int i = Find();
			if(i == -1)
				break;
			else {
				swap(A[idx[i]],A[idx[0]]);
				swap(idx[0],idx[i]);
				st.insert(0);
				cnt ++;
			}
		} else {
			int i = idx[0];
			swap(A[idx[i]],A[idx[0]]);
			swap(idx[i],idx[0]);
			st.erase(i);
			if(A[0] == 0)
				st.erase(0);
			cnt ++;
		}
	}
	printf("%d",cnt);
	return 0;
}
