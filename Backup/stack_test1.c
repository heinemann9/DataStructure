#include <stdio.h>

#define MAX_STACK_SIZE 100
int stack[MAX_STACK_SIZE];
int top = -1;

int is_empty(){
	return (top == -1);
}

int is_full(){
	return (top == (MAX_STACK_SIZE-1));
}

void push(int item){
	if(is_full()){
		fprintf(stderr, "stack is full\n");
	}else
		stack[++top] = item;
	
}

int pop(){
	if(is_empty()){
		fprintf(stderr, "stack is empty\n");
	}else
		return stack[top--];
}

int peek(){
	if(is_empty()){
		fprintf(stderr, "stack is empty\n");
	}else
		return stack[top];
}

int main(int argc, char* argv[]){
	
	push(1);
	push(2);
	push(3);
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",is_empty());
	return 0;
}
