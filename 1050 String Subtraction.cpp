#include <iostream>
#include <string>
using namespace std;
bool table[128] = {false};
int main() {
	string s1,s2,s3 = "";
	getline(cin,s1);
	getline(cin,s2);
	for(auto it = s2.begin(); it != s2.end(); it ++)
		table[*it] = true;
	for(auto it = s1.begin(); it != s1.end(); it ++)
		if(!table[*it])
			s3.push_back(*it);
	printf("%s",s3.c_str());
	return 0;
}


