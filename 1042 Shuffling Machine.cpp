#include <iostream>
#include <string>
using namespace std;
int K;
string card[55],num[14] = {"0","1","2","3","4","5","6","7","8","9","10","11","12","13"};
string tmp[55];
int idx[55];
int main() {
	int cnt = 1;
	for(int i = 1; i <= 13; i ++)
		card[cnt ++] = "S" + num[i];
	for(int i = 1; i <= 13; i ++)
		card[cnt ++] = "H" + num[i];
	for(int i = 1; i <= 13; i ++)
		card[cnt ++] = "C" + num[i];
	for(int i = 1; i <= 13; i ++)
		card[cnt ++] = "D" + num[i];
	card[cnt ++] = "J1";
	card[cnt ++] = "J2";
	scanf("%d",&K);
	for(int i = 1; i <= 54; i ++)
		cin >> idx[i];
	for(int i = 0; i < K; i ++) {
		for(int j = 1; j <= 54; j ++)
			tmp[idx[j]] = card[j];
		for(int j = 1; j <= 54; j ++)
			card[j] = tmp[j];
	}
	for(int i = 1; i < 54; i ++)
		cout << card[i] << " ";
	cout << card[54];
	return 0;
}
