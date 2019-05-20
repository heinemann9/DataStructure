#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

// (char *)malloc(100)
// (int *)malloc(sizeof(int))
// (struct Book*)malloc(sizeof(struct Book))
struct example{
	int number;
	char name[10];
};

int main(int argc, char* argv[]){
	
	struct example *e;
	e = (struct example *)malloc(2*sizeof(struct example));
	if(e == NULL){
		fprintf(stderr,"can't allocate memory\n");
		exit(1);
	}

	e->number = 1;
	strcpy(e->name, "Park");
	(e+1)->number = 2;
	strcpy((e+1)->name, "Kim");
	printf("%d, %s / %d, %s\n", e->number, e->name, (e+1)->number, (e+1)->name);

	free(e);

	char *string;
	string = (char *)malloc(1000);
	if(string == NULL)
		printf("Insufficient memory available\n");
	else{
		printf("Allocated 1000 bytes\n");
		free(string);
		printf("Memory freed\n");
	}
}
