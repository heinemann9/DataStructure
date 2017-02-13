#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode{
	char data[4];
	struct ListNode* link;
} listnode;

typedef struct{
	listnode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void){
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;
	return L;
}

void freeLinkedList_h(linkedList_h* L){
	listnode* p;
	while(L->head != NULL){
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

void printList(linkedList_h* L){
	listnode* p;
	printf("L = (");
	p = L->head;
	while(p != NULL){
		printf("%s",p->data);
		p = p->link;
		if(p != NULL) printf(", ");
	}
	printf(") \n");
}

void insertFirstNode(linkedList_h *L, char *x){
	listnode* newNode;
	newNode = (listnode*)malloc(sizeof(listnode));
	strcpy(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

void insertMiddleNode(linkedList_h* L,listnode* pre, char *x){
	listnode* newNode;
	newNode = (listnode*)malloc(sizeof(listnode));
	strcpy(newNode->data, x);
	if(L == NULL){
		newNode->link = NULL;
		L->head = newNode;
	}else if(pre == NULL){
		L->head = newNode;
	}else{
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void insertLastNode(linkedList_h* L, char *x){
	listnode* newNode;
	listnode* temp;
	newNode = (listnode*)malloc(sizeof(listnode));
	strcpy(newNode->data, x);
	newNode->link = NULL;
	if(L->head == NULL){
		L->head = newNode;
		return;
	}
	temp = L->head;
	while(temp->link != NULL)
		temp = temp->link;
	temp->link = newNode;
}

void deleteNode(linkedList_h* L, listnode* p){
	listnode* pre;
	if(L->head == NULL)
		return ;
	if(L->head->link == NULL){
		free(L->head);
		L->head = NULL;
		return ;
	}else if(p == NULL)
		return ;
	else{
		pre = L->head;
		while(pre->link != p){
			pre = pre->link;
		}
		pre->link = p->link;
		free(p);
	}
}

listnode* searchNode(linkedList_h* L,char* x){
	listnode *temp;
	temp = L->head;
	while(temp != NULL){
		if(strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;
	}
	return temp;
}

void reverse(linkedList_h* L){
	listnode* p;
	listnode* q;
	listnode* r;
	
	p = L->head;
	q = NULL;
	r = NULL;
	
	while(p != NULL){
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	L->head = q;
}

int main(int argc, char* argv[]){
	
	linkedList_h* L;
	listnode* p;
	L = createLinkedList_h();
	//printf("(1) create empty list\n");
	//printList(L); getchar();
	
	printf("(1) insert [Mon], [Wen], [Sun] node\n");
	insertFirstNode(L,"Mon"); insertLastNode(L, "Wen"); insertLastNode(L, "Sun");				
	printList(L); getchar();
	 
	printf("(2) search [Wen] at the list\n");
	p = searchNode(L, "Wen");
	if(p == NULL)
		printf("no data that you are searching for\n");
	else
		printf("found [%s]\n", p->data);
	getchar();

	printf("(3) insert [Wen] after [Fri] Node\n");
	insertMiddleNode(L, p, "Fri");
	printList(L); getchar();

	printf("(4) delete [Sun] Node at the list\n");
	p = searchNode(L, "Sun");
	deleteNode(L, p);
	printList(L); getchar();
		
	printf("(5) change the list order reversly\n");
	reverse(L);
	printList(L);

	freeLinkedList_h(L);
	getchar();

	return 0;

}
	
