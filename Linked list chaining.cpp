#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int SIZE = 20;

struct node{
	int key;
	node *next;
}*hasht[SIZE];

node *createNew(int key){
	node *newNode = (node*)malloc(sizeof(node));
	newNode->key = key;
	newNode->next= NULL;
	return newNode;
}

int hash_folding(int key){
	int sum = 0;
	while(key > 0){
		int part = key % 100;
		sum += part;
		key /= 100;
	}
	return sum % SIZE;
}

int main(){
	int keys[] = {65,65,74,33,23};
	puts("hash table (handling with chaining)");
	
	for(int i = 0; i < SIZE; i++){
		hasht[i] = NULL;
	}
	
	for(int i = 0; i < sizeof(keys)/sizeof(keys[0]); i++){
		int index =  hash_folding(keys[i]);
		node *newNode= createNew(keys[i]);
		newNode->next = hasht[index];
		hasht[index] = newNode;
	}
	
	for(int i = 0; i < SIZE; i++){
		printf("index[%d] : ", i);
		node *curr = hasht[i];
		while(curr != NULL){
			printf("%d  ", curr->key);
			curr= curr->next;
		}
		puts("");
	}
	return 0;
}
