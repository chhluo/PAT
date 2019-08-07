#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 1010
int N;
vector <int> pre;
bool flag = true;
struct Node {
	int d;
	Node *l, *r;
	Node(int d_):d(d_),l(NULL),r(NULL) {}
};
typedef Node * Btree;
void BuildBST(Btree & T,vector <int> &seq) {
	if(seq.size() > 0) {
		unsigned int i;
		vector <int> left,right;
		for(i = 1; i < seq.size(); i ++)
			if(seq[i] < seq[0])
				left.push_back(seq[i]);
			else
				break;
		for(; i < seq.size(); i ++) {
			right.push_back(seq[i]);
			if(seq[i] < seq[0])
				flag = false;
		}
		T = new Node(seq[0]);
		if(flag) BuildBST(T->l,left);
		if(flag) BuildBST(T->r,right);
		if(!flag) delete T;
	}
}
void BuildMirrorBST(Btree & T,vector <int> &seq) {
	if(seq.size() > 0) {
		unsigned int i;
		vector <int> left,right;
		for(i = 1; i < seq.size(); i ++)
			if(seq[i] >= seq[0])
				left.push_back(seq[i]);
			else
				break;
		for(; i < seq.size(); i ++) {
			right.push_back(seq[i]);
			if(seq[i] >= seq[0])
				flag = false;
		}
		T = new Node(seq[0]);
		if(flag) BuildMirrorBST(T->l,left);
		if(flag) BuildMirrorBST(T->r,right);
		if(!flag) delete T;
	}
}
int cnt = 0;
void PostOrder(Btree T) {
	if(T) {
		PostOrder(T->l);
		PostOrder(T->r);
		printf("%d%c",T->d,cnt ++ < N - 1 ? ' ':'\n');
	}
}
int main() {
	Btree T = NULL;
	cin >> N;
	int tmp;
	for(int i = 0; i < N; i ++) {
		cin >> tmp;
		pre.push_back(tmp);
	}
	flag = true;
	BuildBST(T,pre);
	if(flag) {
		printf("YES\n");
		PostOrder(T);
	} else {
		flag = true;
		T = NULL;
		BuildMirrorBST(T,pre);
		if(flag) {
			printf("YES\n");
			PostOrder(T);
		} else
			printf("NO");
	}
	return 0;
}

