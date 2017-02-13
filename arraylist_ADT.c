#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int element;
typedef struct{
	element list[MAX_LIST_SIZE];
	int length;
} ArrayListType;

void error(char *msg){
	fprintf(stderr,"%s\n",msg);
	exit(1);
}

void init(ArrayListType *L){
	L->length = 0;
}

int is_empty(ArrayListType *L){
	return L->length == 0;
}

int is_full(ArrayListType *L){
	return L->length == MAX_LIST_SIZE;
}

void display(ArrayListType *L){
	int i;
	for(i = 0; i < L->length; i++)
		printf("%d\n", L->list[i]);
}

void add(ArrayListType *L, int pos, element item){
	if(!is_full(L) && (pos >= 0) && (pos <= L->length)){
		int i;
		for(i = (L->length-1); i >= pos; i--)
			L->list[i+1] = L->list[i];
		L->list[pos] = item;
		L->length++;
	}
}

element delete(ArrayListType *L, int pos){
	int i;
	element item;
	if(pos < 0 || pos >= L->length)
		error("pos error");
	item = L->list[pos];
	for(i = pos; i < (L->length-1); i++)
		L->list[i] = L->list[i+1];
	L->length--;
	return item;
}

ArrayListType replace(ArrayListType *L, int pos, element item){
	L->list[pos] = item;
	return L;
}

void get_entry(ArrayListTyp *L, int pos){
	
}

int get_length(ArrayListType *L){
	return L->length;
}

void clear(ArrayListType *L){
	free(L);
}

int main(int argc, char* argv[]){

	ArrayListType list1;
	ArrayListType *plist;

	init(&list1);
	add(&list1, 0, 10);
	add(&list1, 0, 20);
	add(&list1, 0, 30);
	display(&list1);
	
	plist = (ArrayListType *)malloc(sizeof(ArrayListType));
	init(plist);
	add(plist, 0, 10);
	add(plist, 0, 20);
	add(plist, 0, 30);
	display(plist);
	
	free(plist);

	return 0;
}	
