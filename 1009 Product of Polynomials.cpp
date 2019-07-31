#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
const double eps = 1e-8;
struct Node {
	int exp;
	double cof;
	Node() {}
	Node(int e,double c):exp(e),cof(c) {}
};
vector <Node> A,B,C;
void oneMultiPoly(Node X,vector <Node> & Y,vector <Node> &result) {
	result.clear();
	if(fabs(X.cof) < eps)
		return;
	for(unsigned int i = 0; i < Y.size(); i ++) {
		result.push_back(Node(X.exp + Y[i].exp,X.cof * Y[i].cof));
	}
}

void add(vector <Node> &X,vector <Node> &Y,vector <Node> &result) {
	unsigned int i = 0,j = 0;
	while(i < X.size() && j < Y.size()) {
		if(X[i].exp > Y[j].exp)
			result.push_back(X[i ++]);
		else if(X[i].exp < Y[j].exp)
			result.push_back(Y[j ++]);
		else if(fabs(X[i].cof + Y[j].cof) < eps) {
			i ++;
			j ++;
		} else {
			result.push_back(Node(X[i].exp,X[i].cof + Y[j].cof));
			i ++;
			j ++;
		}
	}
	while(i < X.size())
		result.push_back(X[i ++]);
	while(j < Y.size())
		result.push_back(Y[j ++]);
}

void multiply(vector <Node> &A,vector <Node> &B,vector <Node> &C) {
	vector <Node> sum,product;
	for(unsigned int i = 0; i < A.size(); i ++) {
		oneMultiPoly(A[i],B,sum);
		add(sum,product,C);
		product = C;
		C.clear();
	}
	C = product;
}
void readPoly(vector <Node> & v) {
	int n,e;
	double c;
	scanf("%d",&n);
	for(int i = 0; i < n; i ++) {
		scanf("%d%lf",&e,&c);
		v.push_back(Node(e,c));
	}
}
int main() {
	readPoly(A);
	readPoly(B);
	multiply(A,B,C);
	printf("%d",C.size());
	for(unsigned int i = 0; i < C.size(); i ++) {
		printf(" %d %.1lf",C[i].exp,C[i].cof);
	}
	return 0;
}
