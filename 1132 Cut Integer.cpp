#include <iostream>
#include <string>
using namespace std;
int N;
int main() {
	scanf("%d",&N);
	string s;
	int x,y,z;
	for(int i = 0; i < N; i ++) {
		cin >> s;
		int len = s.length();
		x = stoi(s);
		y = stoi(s.substr(0,len / 2));
		z = stoi(s.substr(len / 2));
		if(z == 0 || y == 0)
			printf("No\n");
		else
			printf("%s\n",x % (y * z) == 0 ? "Yes":"No");
	}
	return 0;
}
