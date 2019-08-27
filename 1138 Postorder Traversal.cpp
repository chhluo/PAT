#include <iostream>
using namespace std;
#define MAXN 50010
int N,preSeq[MAXN],inSeq[MAXN];
void Find(int pre_s,int pre_t,int in_s,int in_t,bool &flag) {
	if(pre_s < pre_t && flag) {
		int mid = in_s;
		while(mid < in_t && inSeq[mid] != preSeq[pre_s]) mid ++;
		int ln = mid - in_s;
		int rn = in_t - mid - 1;
		if(ln == 0 && rn == 0 && flag) {
			printf("%d",preSeq[pre_s]);
			flag = false;
		} else if(flag) {
			Find(pre_s + 1,pre_s + 1 + ln,in_s,mid,flag);
			Find(pre_s + 1 + ln,pre_t,mid + 1,in_t,flag);
		}
	}
}

int main() {
	scanf("%d",&N);
	for(int i = 0; i < N; i ++)
		scanf("%d",preSeq + i);
	for(int i = 0; i < N; i ++)
		scanf("%d",inSeq + i);
	bool flag = true;
	Find(0,N,0,N,flag);
	return 0;
}
