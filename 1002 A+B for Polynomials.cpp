#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const double eps = 1e-8;
struct Node{
	int exp;
	double cof;
	Node(int exp_,double cof_):exp(exp_),cof(cof_){}
};
vector <Node> a,b,c;
void readPoly(vector <Node> & p){
	int n,exp;
	double cof;
	scanf("%d",&n);
	for(int i = 0;i < n;i ++){
		scanf("%d %lf",&exp,&cof);
		p.push_back(Node(exp,cof));
	}
}
int main(){
	readPoly(a);
	readPoly(b);
	unsigned int i = 0,j = 0;
	while (i < a.size() && j < b.size()){
		if(a[i].exp > b[j].exp)
			c.push_back(a[i ++]);
		else if(a[i].exp < b[j].exp)
			c.push_back(b[j ++]);
		else if(fabs(a[i].cof + b[j].cof) < eps){
			i ++;
			j ++;
		}else{
			c.push_back(Node(a[i].exp,a[i].cof + b[j].cof));
			i ++;
			j ++;
		}
	}
	while (i < a.size())
		c.push_back(a[i ++]);
	while (j < b.size())
		c.push_back(b[j ++]);
	if(c.size() == 0)
		printf("0");
	else{
		printf("%d",c.size());
		for(i = 0;i < c.size();i ++)
			printf(" %d %.1lf",c[i].exp,c[i].cof);
	}
	return 0;
}
