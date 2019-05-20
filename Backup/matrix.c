#include <stdio.h>
#define ROWS 3
#define COLS 3

void sparse_matrix_add1(int A[ROWS][COLS], int B[ROWS][COLS], int C[ROWS][COLS]){

	int i, j;
	for(i = 0; i < ROWS; i++){
		for(j = 0; j < COLS; j++){
			C[i][j] = A[i][j] + B[i][j];
			printf("%d ",C[i][j]);
		}
		printf("\n");
	}
	
}

int main(int argc, char* argv[]){

	int array1[ROWS][COLS] = { {2, 3, 0},
				   {8, 9, 1},
				   {7, 0, 5}};
	int array2[ROWS][COLS] = { {1, 0, 0},
				   {1, 0, 0},
				   {1, 0, 0}};
	int array3[ROWS][COLS];
	sparse_matrix_add1(array1, array2, array3);

	return 0;
}
