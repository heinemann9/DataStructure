#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct {
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];
}element;

element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty(){
	return (top == -1);
}

int is_full(){
	return (top == (MAX_STACK_SIZE-1));
}

void push(element item){
	if(is_full()){
		fprintf(stderr,"stack is full\n");
	}else{
		stack[++top] = item;
	}
}

element pop(){
	if(is_empty()){
		fprintf(stderr,"stack is empty\n");
	}else{
		return stack[top--];
	}
}

element peek(){
	if(is_empty()){
		fprintf(stderr,"stack is empty\n");
	}else{
		return stack[top];
	}
}

int main(int argc, char* argv[]){

	element ie, oe;
	strcpy(ie.name, "HongGilDong");
	strcpy(ie.address, "Seoul");
	ie.student_no = 20053001;
	push(ie);
	oe = pop();
	printf("name = %s\n",oe.name);
	printf("address = %s\n", oe.address);
	printf("student no = %d\n", oe.student_no);

	return 0;
}
