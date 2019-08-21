#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define MAXN 100010
int N,A[MAXN];
vector <int> ans;
set <int> st;
int main() {
	scanf("%d",&N);
	for(int i = 0; i < N; i ++) {
		scanf("%d",A + i);
		st.insert(A[i]);
	}
	int Min,Max = 0;
	for(int i = 0; i < N; i ++) {
		st.erase(A[i]);
		Min = i + 1 < N ? *st.begin() :0x3fffffff;
		if(A[i] > Max && A[i] < Min)
			ans.push_back(A[i]);
		if(A[i] > Max)
			Max = A[i];
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	if(ans.size() == 0)
		printf("\n");
	else {
		for(unsigned int i = 0; i < ans.size(); i ++)
			printf("%d%c",ans[i],i + 1 < ans.size() ? ' ':'\n');
	}
	return 0;
}
