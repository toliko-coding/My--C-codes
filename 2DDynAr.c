#include<stdio.h>
#include<stdlib.h>
int main() {
	int row, column, **matrix = NULL;
	printf("Enter number of row :");
	scanf("%d", &row);
	printf("Enter number of column :");
	scanf("%d", &column);

	// The dynamic allocation for the matrix
	matrix = (int**)malloc(row * sizeof(int*));
	if(matrix == NULL) {
		printf(" Not enougth memory! ");
		exit(1); // exit from program
	}
	for (int i = 0; i < row; i++) {
		matrix[i] = (int*)malloc(column * sizeof(int));
		if (matrix[i] == NULL) {
			printf(" Not enougth memory! ");
			// free memory we have been able to get
			for (int k = 0; k < i; k++)
				free(matrix[k]);
			free(matrix);
			exit(1); // exit from program
		}

		// input a row
		printf(" Enter %d row , total %d elements ", (i + 1), column);
		for (int j = 0; j < column; j++)
			scanf("%d", &matrix[i][j]);
	}


	// print all data 
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++)
			printf("%4d", matrix[i][j]);
		printf("\n");
	}

	//free all data
	for (int i = 0; i < row; i++) {
		free(matrix[i]);
		matrix[i] = NULL;
	}
		
	free(matrix);
	matrix = NULL;
	return 0;
}