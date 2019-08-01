#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
char N1[30],N2[30],tmp[30];
int tag,radix,ans;
long long int v1,v2;
long long int transformDecimal(char s[], int len,int radix) {
	long long int v = 0;
	long long int power = 1;
	for(int i = len - 1; i >= 0; i --) {
		if(isdigit(s[i]))
			v += power * (s[i] - '0');
		else
			v += power * (s[i] - 'a' + 10);
		power *= radix;
	}
	return v;
}

int main() {
	scanf("%s %s %d %d",N1,N2,&tag,&radix);
	if (tag == 2) {
		strcpy(tmp,N2);
		strcpy(N2,N1);
		strcpy(N1,tmp);
	}
	int len1 = strlen(N1), len2 = strlen(N2);
	v1 = transformDecimal(N1,len1,radix);
	ans = -1;
	char c = *max_element(N2,N2 + len2);
	//基数最小大于数中最大的数字，最大是另外一个数加1
	long long int minRadix = isalpha(c) ? (c - 'a' + 11):( c - '0' + 1);
	long long int maxRadix = max(minRadix,v1 + 1);
	while(minRadix <= maxRadix) {
		long long int mid = (maxRadix + minRadix) / 2;
		v2 = transformDecimal(N2,len2,mid);
		if(v2 < 0 || v2 > v1)//v2 溢出的话，符号为就变1
			maxRadix = mid - 1;
		else if(v2 < v1)
			minRadix = mid + 1;
		else {
			ans = mid;
			break;
		}
	}
	if(ans != -1)
		printf("%d",ans);
	else
		printf("Impossible");
	return 0;
}
