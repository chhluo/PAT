#include <iostream>
#include <string>
using namespace std;
#define MAXN 40
int N,M;
int inSeq[MAXN],postSeq[MAXN];
typedef struct Node * BTree;
struct Node {
	int data;
	BTree left,right;
	Node(int dd):data(dd),left(NULL),right(NULL) {}
};
void buildTree(BTree &root,int in_s,int in_t,int post_s,int post_t) {
	if(in_s < in_t) {
		root = new Node(postSeq[post_t - 1]);
		int mid = in_s;
		while(mid < in_t && inSeq[mid] != postSeq[post_t - 1]) mid ++;
		int n = mid - in_s;
		buildTree(root->left,in_s,mid,post_s,post_s + n);
		buildTree(root->right,mid + 1,in_t,post_s + n,post_t - 1);
	}
}
void Siblings(BTree root,int s1,int s2,bool &flag) {
	if(root) {
		if(root->left && root->right &&
		        ((root->left->data == s1 && root->right->data == s2) || (root->left->data == s2 && root->right->data == s1)))
			flag = true;
		Siblings(root->left,s1,s2,flag);
		Siblings(root->right,s1,s2,flag);
	}
}
void Parent(BTree root,int p,int c,bool &flag) {
	if(root) {
		if(root->data == p && ((root->left && root->left->data == c) ||
		                       (root->right && root->right->data == c)))
			flag = true;
		Parent(root->left,p,c,flag);
		Parent(root->right,p,c,flag);
	}
}

void Child(BTree root,int p,int c,bool ll,bool &flag) {
	if(root) {
		if(ll && root->data == p && root->left && root->left->data == c)
			flag = true;
		if(!ll && root->data == p && root->right && root->right->data == c)
			flag = true;
		Child(root->left,p,c,ll,flag);
		Child(root->right,p,c,ll,flag);
	}
}
void Level(BTree root,int depth,int v1,int v2,int &l1,int &l2) {
	if(root) {
		if(root->data == v1) l1 = depth;
		if(root->data == v2) l2 = depth;
		Level(root->left,depth + 1,v1,v2,l1,l2);
		Level(root->right,depth + 1,v1,v2,l1,l2);
	}
}
void FullTree(BTree root,bool &flag) {
	if(root) {
		if((root->left && !root->right) || (!root->left && root->right))
			flag = false;
		FullTree(root->left,flag);
		FullTree(root->right,flag);
	}
}
int main() {
//	freopen("in.txt","r",stdin);
	scanf("%d",&N);
	for(int i = 0; i < N; i ++)
		scanf("%d", postSeq + i);
	for(int i = 0; i < N; i ++)
		scanf("%d", inSeq + i);
	scanf("%d\n",&M);
	BTree T = NULL;
	buildTree(T,0,N,0,N);
	string query;
	for(int i = 0; i < M; i ++) {
		getline(cin,query);
		bool flag = false;
		if(query.find("root") != query.npos) {
			int r;
			sscanf(query.c_str(),"%d",&r);
			flag = T->data == r;
		} else if(query.find("siblings") != query.npos) {
			int s1,s2;
			sscanf(query.c_str(),"%d and %d",&s1,&s2);
			Siblings(T,s1,s2,flag);
		} else if(query.find("parent") != query.npos) {
			int p,c;
			sscanf(query.c_str(),"%d is the parent of %d",&p,&c);
			Parent(T,p,c,flag);
		} else if(query.find("left child") != query.npos) {
			int p,c;
			sscanf(query.c_str(),"%d is the left child of %d",&c,&p);
			Child(T,p,c,true,flag);
		} else if(query.find("right child") != query.npos) {
			int p,c;
			sscanf(query.c_str(),"%d is the right child of %d",&c,&p);
			Child(T,p,c,false,flag);
		} else if(query.find("level") != query.npos) {
			int v1,v2,l1 = -1,l2 = -1;
			sscanf(query.c_str(),"%d and %d",&v1,&v2);
			Level(T,0,v1,v2,l1,l2);
			flag = l1 == l2;
		} else {
			flag = true;
			FullTree(T,flag);
		}
		printf("%s\n",flag ? "Yes":"No");
	}
	return 0;
}
