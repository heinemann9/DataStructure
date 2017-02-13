#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#define FILE_NAME_LENGTH 256
#define CONTENT_LENGTH 1000

typedef struct ListNode{
	char content[CONTENT_LENGTH];
	struct ListNode *link;
}ListNode;

typedef struct LinkedListType{
	ListNode *head;
	int length;
}LinkedListType;

void init(LinkedListType *ListType);
void show_menu();
void do_command(char command, LinkedListType *ListType);
void do_insert(LinkedListType *ListType);
void do_delete(LinkedListType *ListType);
void do_read(LinkedListType *ListType);
void do_write(LinkedListType *ListType);
void do_quit(LinkedListType *ListType);
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node);
void remove_node(ListNode **phead, ListNode *p, ListNode *new_node);
int is_empty(LinkedListType *ListType);
void clear(LinkedListType *ListType);

int main(int argc, char* argv[]){

	LinkedListType ListType;
	char command;
	
	init(&ListType);
	do{
		show_menu();
		command = getchar();
		while( getchar() != '\n' );
		do_command(command,&ListType);
		
	}while(command != 'q');
	
}

void init(LinkedListType *ListType){
	ListType->head = NULL;
	ListType->length = 0;	
}

void show_menu(){
	printf("************\ni: 입력\nd: 삭제\nr: 파일 읽기\nw: 파일 쓰기\nq: 종료\n************\n");
}

void show_result(LinkedListType *ListType){
	ListNode *p = ListType->head;
	if(p != NULL){
		printf("************\n");
		while(p != NULL){
			printf("%s",p->content);
			p = p->link;
		}
		printf("************\n");
	}else{
		printf("************\n");
		printf("empty\n");
		printf("************\n");
	}
}

void do_command(char command, LinkedListType *ListType){

	switch(command){
	case 'i':
		do_insert(ListType);
		break;
	case 'd':
		do_delete(ListType);
		break;
	case 'r':
		do_read(ListType); 
		break;
	case 'w':
		do_write(ListType);
		break;
	case 'q':
		do_quit(ListType);
		return ;
		break;
	default:
		return ;
		break;
	}
	show_result(ListType);
}

void do_insert(LinkedListType *ListType){
	ListNode *l = (ListNode*)malloc(sizeof(ListNode));
	printf("insert content:");
	scanf("%s",l->content);
	l->link = NULL;
	while( getchar() != '\n' );
	strcat(l->content, "\n");
	insert_node(&(ListType->head), NULL, l);
	ListType->length++;
}
	
void insert_node(ListNode **phead, ListNode *p, ListNode *new_node){
	if(*phead == NULL){
		new_node->link = NULL;
		*phead = new_node;
	}else if(p == NULL){
		new_node->link = *phead;
		*phead = new_node;
	}else{
		new_node->link = p->link;
		p->link = new_node;
	}
}

void do_delete(LinkedListType *ListType){
	remove_node(&(ListType->head), NULL,ListType->head);
	ListType->length--;
}

void remove_node(ListNode **phead, ListNode *p, ListNode *removed){
	if( p == NULL ){
		*phead = (*phead)->link;
	}else{
		p->link = removed->link;
	}
	free(removed);
}
void do_read(LinkedListType *ListType){
	char fname[FILE_NAME_LENGTH];
	FILE *fd;
	char f_content[CONTENT_LENGTH];
	
	if(!is_empty(ListType)){
		clear(ListType);	
	}
	init(ListType);
	
	printf("file name:");
	scanf("%s",fname);
	while( getchar() != '\n' );
	if((fd = fopen(fname,"rt")) == NULL){
		printf("can't open the file\n");
		return ;
	}

	while(fgets(f_content, CONTENT_LENGTH, fd) != NULL){
		ListNode *p = (ListNode*)malloc(sizeof(ListNode));
		strcpy(p->content, f_content);
		p->link = NULL;
		insert_node(&(ListType->head), NULL, p);	
		ListType->length++;
	}
	fclose(fd);
}

void do_write(LinkedListType *ListType){
	char fname[FILE_NAME_LENGTH];
	FILE *fd;
	int i;
	ListNode *p = ListType->head;
	char f_content[CONTENT_LENGTH];

	printf("file name:");
	scanf("%s",fname);
	while( getchar() != '\n');
	if((fd = fopen(fname,"wt")) == NULL){
		printf("can't open file\n");
		return ;
	}
	
	for(i = 0; i < ListType->length; i++){
		fputs(p->content, fd);
		p = p->link;	
	}
	
	fclose(fd);
	printf("write complete\n");
}

void do_quit(LinkedListType *ListType){
	printf("quit\n");
}

int is_empty(LinkedListType *ListType){
	if(ListType->head == NULL) return 1;
	else return 0;
}

void clear(LinkedListType *ListType){
	int i;
	for(i = 0; ListType->length; i++){
		do_delete(ListType);
	}
}
