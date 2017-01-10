#include <stdio.h>
#define MAX_DEGREE 101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;

polynomial poly_add(polynomial a, polynomial b){

	polynomial c;
	int Apos = 0, Bpos = 0, Cpos = 0;	
	int a_degree = a.degree;
	int b_degree = b.degree;
	c.degree = a.degree > b.degree ? a.degree : b.degree;
	
	while(Apos <= a.degree && Bpos <= b.degree){
		if(a_degree > b_degree){
			c.coef[Cpos++] = a.coef[Apos++];
			a_degree--;
		}else if(a_degree == b_degree){
			c.coef[Cpos++] = a.coef[Apos++] + b.coef[Bpos++];
			a_degree--; 
			b_degree--;
		}else{
			c.coef[Cpos++] = b.coef[Bpos++];
			b_degree--;
		}
	}
	
	return c;
}

int main(int argc, char* argv[]){
	polynomial a = {5, {3, 6, 0, 0, 0, 10}};
	polynomial b = {4, {7, 0, 5, 0, 1}};
	polynomial c;
	int i;

	c = poly_add(a,b);
	
	printf("c.degree = %d, ", c.degree);
	for(i = 0; i < c.degree; i++){
		printf("c.coef[%d] = %f, ", i, c.coef[i]);
	}
	printf("\n");

	return 0;
}
