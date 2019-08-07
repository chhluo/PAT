#include <iostream>
#include <string>
using namespace std;
string s;

int symmetric(int center,int len){
	int left = center - 1,right = center + 1,cnt1 = 1,cnt2 = 0;
	while(left >= 0 && right < len && s[left] == s[right]){
		cnt1 += 2;
		left --;
		right ++;
	}
	left = center;
	right = center + 1;
	cnt2 = 0;
	while(left >= 0 && right < len && s[left] == s[right]){
		cnt2 += 2;
		left --;
		right ++;
	}
	return cnt1 < cnt2 ? cnt2 : cnt1;
}

int main(){
	getline(cin,s);
	int len = s.length();
	int cnt = 0,tmp;
	for(int i = 0;i < len;i ++){
		tmp = symmetric(i,len);
			cnt = cnt < tmp ? tmp : cnt;
	}
	printf("%d",cnt);

	return 0;
}