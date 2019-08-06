#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100010
int Nc,Np;
int products[MAXN],coupons[MAXN];
int main() {
	cin >> Nc;
	for(int i = 0; i < Nc; i ++)
		cin >> coupons[i];
	cin >> Np;
	for(int i = 0; i < Np; i ++)
		cin >> products[i];
	sort(coupons, coupons + Nc);
	sort(products,products + Np);
	int total = 0;
	for(int i = 0; i < Nc && i < Np && coupons[i] < 0 && products[i] < 0; i ++)
		total += coupons[i] * products[i];
	int i = Nc -1,j = Np - 1;
	while(i >= 0 && j >= 0 && coupons[i] > 0 && products[j] > 0)
		total += coupons[i --] * products[j --];
	printf("%d",total);
	return 0;
}

