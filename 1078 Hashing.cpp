#include <iostream>
#include <cmath>
using namespace std;
int N,M;
typedef enum {Empty,Full} InfoType;
struct Entry{
	InfoType info;
	int data;
};
struct HashEntry{
	int size;
	Entry * elements;
};
typedef struct HashEntry * HashTable;
bool Prime(int n){
	if(n == 1) return false;
	else if(n == 2) return true;
	else{
		int end = sqrt(n);
		for(int i = 2;i <= end;i ++)
			if(n % i == 0)
				return false;
		return true;
	}
}
int AdjustN(int n){
	while(!Prime(n)) n ++;
	return n;
}
HashTable Create(int n){
	n = AdjustN(n);
	HashTable T = new HashEntry;
	T->size = n;
	T->elements = new Entry[n];
	for(int i = 0;i < T->size;i ++)
		T->elements[i].info = Empty;
	return T;
}
int Hash(HashTable T,int key){
	return key % T->size;
}
int Find(HashTable T,int key){
	int crtpos,pos;
	crtpos = pos = Hash(T,key);
	int i = 1,lst = T->size / 2;
	while(T->elements[crtpos].info != Empty && i <= lst){
		crtpos = pos + i * i;
		i ++;
		while(crtpos > T->size) 
			crtpos %= T->size;
	}
	return T->elements[crtpos].info != Empty ? -1 : crtpos; 
}
int Insert(HashTable T,int key){
	int pos = Find(T,key);
	if(pos != -1){
		T->elements[pos].info = Full;
		T->elements[pos].data = key;
	}
	return pos;
}
int main(){
	scanf("%d%d",&M,&N);
	int key,pos;
	HashTable T = Create(M);
	for(int i = 0;i < N;i ++){
		scanf("%d",&key);
		pos = Insert(T,key);
		if(pos == -1)
			printf("-%c",i + 1 < N ? ' ':'\n');
		else
			printf("%d%c",pos,i + 1 < N ? ' ':'\n');
	}
	return 0;
}