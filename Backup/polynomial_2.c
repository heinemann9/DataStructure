#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101

struct {
	float coef;
	int expon;
}terms[MAX_TERMS]={{8, 3}, {7, 1}, {1, 0}, {10, 3}, {3, 2}, {1, 0}};
int avail = 6;

char compare(int expoA, int expoB);
void attach(float coef, int expon);
void poly_add2(int Astart, int Aend, int Bstart, int Bend, int *Cstart, int *Cend);

int main(int argc, char* argv[]){

	int Cstart, Cend;
	poly_add2(0, 2, 3, 5, &Cstart, &Cend);
	
	for(Cstart = 0; Cstart <= Cend; Cstart++){
		printf("terms[%d].coef = %f, terms[%d].expon = %d\n",Cstart,terms[Cstart].coef,Cstart,terms[Cstart].expon);
	}
	return 0;
}

char compare(int expoA, int expoB){
	if(expoA > expoB)
		return '>';
	else if(expoA == expoB)
		return '=';
	else
		return '<';
}

void attach(float coef, int expon){
	if(avail>MAX_TERMS){
		fprintf(stderr,"the number of polynomials are too much\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}

void poly_add2(int Astart, int Aend, int Bstart, int Bend, int *Cstart, int *Cend){
	float tempcoef;
	*Cstart = avail;
	while(Astart <= Aend && Bstart <= Bend)
		switch(compare(terms[Astart].expon,terms[Bstart].expon)){
			case '>':
				attach(terms[Astart].coef,terms[Astart].expon);
				Astart++;
			break;
			case '=':	
				tempcoef = terms[Astart].coef + terms[Bstart].coef;
				attach(tempcoef,terms[Astart].expon);
				Astart++; Bstart++;
			break;
			case '<':
				attach(terms[Bstart].coef,terms[Bstart].expon);
				Bstart++;
			break;
		}
	for(;Astart <= Aend; Astart++)
		attach(terms[Astart].coef, terms[Astart].expon);
	for(;Bstart <= Bend; Bstart++)
		attach(terms[Bstart].coef, terms[Bstart].expon);

	*Cend = avail - 1;
}
