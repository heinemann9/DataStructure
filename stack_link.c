#include <stdio.h>
#include <malloc.h>

typedef struct StackNode{
	int item;
	struct StackNode *link;
} StackNode;

typedef struct {
	StackNode *top;
} LinkedStackType;

void init(LinkedStackType *s){
	s->top = NULL;
}

int is_empty(LinkedStackType *s){
	return (s->top == NULL);
}

int is_full(LinkedStackType *s){
	return 0;
}

void push(LinkedStackType *s, int item){
	StackNode *temp = (StackNode*) malloc(sizeof(StackNode));
	if(temp == NULL){
		fprintf(stderr,"allocate memory error\n");
	}else{
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}	
}

int pop(LinkedStackType *s){
	if(is_empty(s)){
		fprintf(stderr,"stack is empty\n");
	}else{
		StackNode *temp = s->top;
		int item = temp->item;
		s->top = s->top->link;
		free(temp);
		return item;
	}
}

int peek(LinkedStackType *s){
	if(is_empty(s)){
		fprintf(stderr,"stack is empty\n");
	}else{
		return s->top->item;
	}
}

int main(int argc, char* argv[]){
	
	LinkedStackType s;
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",pop(&s));
	printf("%d\n",is_empty(&s));

	return 0;
}
