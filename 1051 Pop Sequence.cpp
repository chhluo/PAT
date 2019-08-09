#include <iostream>
#include <stack>
using namespace std;
#define MAXN 1001
int M,N,K;
int seq[MAXN];
bool judge(int seq[],int M,int N){
	stack <int> S;
	int cnt = 1;
	for(int i = 0;i < N;){
		if(S.empty() || S.top() < seq[i]){
			S.push(cnt ++);
			if(S.size() > M)
				return false;
		}else if(S.top() == seq[i ++]){
			S.pop();
		}else
			return false;
	}
	return true;
}

int main(){
	scanf("%d%d%d",&M,&N,&K);
	for(int i = 0;i < K;i ++){
		for(int j = 0;j < N;j ++)
			scanf("%d",seq + j);
		printf("%s\n",judge(seq,M,N)? "YES":"NO");
	}
	return 0;
}

