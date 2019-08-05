#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
int N,M;
map <string,set<int> > TiList,AuList,PuList,KWList,YearList;

void Input(){
	scanf("%d",&N);
	string title,author,publisher,word,year;
	int id;
	for(int i = 0;i < N;i ++){
		scanf("%d\n",&id);
		getline(cin,title);
		TiList[title].insert(id);
		getline(cin,author);
		AuList[author].insert(id);
		while(cin >> word){
			KWList[word].insert(id);
			if(getchar() == '\n') break;
		}
		getline(cin,publisher);
		PuList[publisher].insert(id);
		cin >> year;
		YearList[year].insert(id);
	}
}

void find(map <string,set <int>> &m,string & key){
	if(m.find(key) != m.end())
		for(auto it = m[key].begin(); it != m[key].end();it ++)
			printf("%07d\n",*it);
	else
		printf("Not Found\n");
}

int main(){
	//freopen("in.txt","r",stdin);
	Input();
	scanf("%d\n",&M);
	string query,s;
	for(int i = 0;i < M;i ++){
		getline(cin,query);
		s = query.substr(3);
		printf("%s\n",query.c_str());
		if(query[0] == '1')	find(TiList,s);
		else if(query[0] == '2') find(AuList,s);
		else if(query[0] == '3') find(KWList,s);
		else if(query[0] == '4') find(PuList,s);
		else if(query[0] == '5') find(YearList,s);
	}
	return 0;
}
