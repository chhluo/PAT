#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N;
struct Account {
	string user,psw;
	Account(string uu,string pp):user(uu),psw(pp) {}
};
vector <Account> M;
int main() {
	cin >> N;
	string user,psw;
	bool flag;
	for(int i = 0; i < N; i ++) {
		cin >> user >> psw;
		flag = false;
		for(auto it = psw.begin(); it != psw.end(); it ++)
			if(*it == '1') {
				flag = true;
				*it = '@';
			} else if(*it == '0') {
				flag = true;
				*it = '%';
			} else if(*it == 'l') {
				flag = true;
				*it = 'L';
			} else if(*it == 'O') {
				flag = true;
				*it = 'o';
			}
		if(flag)
			M.push_back(Account(user,psw));
	}
	if(M.size() == 0) {
		if(N == 1)
			printf("There is 1 account and no account is modified");
		else
			printf("There are %d accounts and no account is modified",N);
	} else {
		printf("%d\n",M.size());
		for(unsigned int i = 0; i < M.size(); i ++)
			printf("%s %s\n",M[i].user.c_str(),M[i].psw.c_str());
	}
	return 0;
}
