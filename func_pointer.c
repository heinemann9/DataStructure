#include <stdio.h>

void foo(int a){
	printf("foo : %d\n",a);
}

int main(int argc, char* argv[]){

	void (*f)(int);
	f = foo;
	f(10);
	(*f)(10);

	return 0;
}
