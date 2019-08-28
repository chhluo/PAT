#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int Msize,N,M;
typedef enum {Empty ,Full} InfoType;
struct Entry {
	int data;
	InfoType info;
};
struct HashEntry {
	Entry * Element;
	int size;
};
typedef struct HashEntry * HashTable;
bool Prime(int n) {
	if(n == 1)	return false;
	else if(n == 2)	return true;
	else {
		int e = sqrt(n);
		for(int i = 2; i <= e; i ++)
			if(n % i == 0)
				return false;
		return true;
	}
}
int RedefineN(int n) {
	while(!Prime(n)) n ++;
	return n;
}
HashTable Init(int n) {
	HashTable H = new HashEntry;
	H->size = RedefineN(n);
	H->Element = new Entry[H->size];
	for(int i = 0; i < H->size; i ++)
		H->Element[i].info = Empty;
	return H;
}
int Hash(HashTable H,int key) {
	return key % H->size;
}
int Find(HashTable H,int key,int &t) {
	int pos,curpos,cnt = 0;
	curpos = pos = Hash(H,key);
	while(H->Element[curpos].info == Full && H->Element[curpos].data != key && cnt < H->size) {
		curpos = pos + (cnt + 1) *( cnt + 1);
		curpos %= H->size;
		cnt ++;
	}
	t = cnt + 1;
	return curpos;
}
bool Insert(HashTable H,int key) {
	int t;
	int idx = Find(H,key,t);
	if(H->Element[idx].info == Empty) {
		H->Element[idx].data = key;
		H->Element[idx].info = Full;
		return true;
	} else
		return false;
}

int main() {
	scanf("%d%d%d",&Msize,&N,&M);
	HashTable H = Init(Msize);
	int key;
	for(int i = 0; i < N; i ++) {
		scanf("%d",&key);
		if(!Insert(H,key)) printf("%d cannot be inserted.\n",key);
	}
	int times = 0,t;
	for(int i = 0; i < M; i ++) {
		scanf("%d",&key);
		Find(H,key,t);
		times += t;
	}
	printf("%.1lf\n",1.0 * times / M);
	return 0;
}
