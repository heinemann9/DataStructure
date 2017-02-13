#include <stdio.h>

#define MAX_STACK_SIZE 100

typedef struct{
	int stack[MAX_STACK_SIZE];
	int top;
} StackType;

void init(StackType *s){
	s->top = -1;
}
	
int is_empty(StackType *s){
	return (s->top == -1);
}

int is_full(StackType *s){
	return (s->top == (MAX_STACK_SIZE-1));
}

void push(StackType *s, int item){
	if(is_full(s)){
		fprintf(stderr,"stack is full\n");
	}else{
		s->stack[++(s->top)] = item;
	}
}

int pop(StackType *s){
	if(is_empty(s)){
		fprintf(stderr,"stack is empty\n");
	}else{
		return s->stack[(s->top)--];
	}
}

int peek(StackType *s){
	if(is_empty(s)){
		fprintf(stderr,"stack is empty\n");
	}else{
		return s->stack[(s->top)];
	}
}

int main(int argc, char* argv[]){
	
	StackType s;
	
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
