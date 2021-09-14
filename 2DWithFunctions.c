#include<stdio.h>
#include<stdlib.h>

int** BuildMatrix1(int*,int*);
void BuildMatrix2(int***, int*,int*);
void FreeMatrix(int***, int);

void PrintMatrix(int**, int, int);

int main() {
	int row, column, **matrix = NULL;
	//version1
	matrix = BuildMatrix1(&row, &column);
	// print all data 
	PrintMatrix(matrix, row, column);
	// Free
	FreeMatrix(&matrix, row);
	
	// version 2
	 BuildMatrix2(&matrix,&row, &column);
	// print all data 
	PrintMatrix(matrix, row, column);
	// Free
	FreeMatrix(&matrix, row);
	
	return 0;
}
int** BuildMatrix1(int* pRow, int* pColumn) {
	int ** matrix = NULL;
	printf("Enter number of row :");
	scanf("%d", pRow);
	printf("Enter number of column :");
	scanf("%d", pColumn);
	// The dynamic allocation for the matrix
	matrix = (int**)malloc(*pRow * sizeof(int*));
	if (matrix == NULL) {
		printf(" Not enougth memory! ");
		exit(1); // exit from program
	}
	for (int i = 0; i < *pRow; i++) {
		matrix[i] = (int*)malloc(*pColumn  * sizeof(int));
		if (matrix[i] == NULL) {
			printf(" Not enougth memory! ");
			// free memory we have been able to get
			FreeMatrix(&matrix, i);
			exit(1); // exit from program
		}

		// input a row
		printf(" Enter %d row , total %d elements ", (i + 1), *pColumn);
		for (int j = 0; j < *pColumn; j++)
			scanf("%d", &matrix[i][j]);
	}

	return matrix;
}

void BuildMatrix2(int*** pMatrix, int* pRow, int* pColumn) {
	printf("Enter number of row :");
	scanf("%d", pRow);
	printf("Enter number of column :");
	scanf("%d", pColumn);

	// The dynamic allocation for the matrix
	*pMatrix = (int**)malloc(*pRow * sizeof(int*));
	if (*pMatrix == NULL) {
		printf(" Not enougth memory! ");
		exit(1); // exit from program
	}
	for (int i = 0; i < *pRow; i++) {
		(*pMatrix)[i] = (int*)malloc(*pColumn * sizeof(int));
		if ((*pMatrix)[i] == NULL) {
			printf(" Not enougth memory! ");
			// free memory we have been able to get
			FreeMatrix(pMatrix, i);
			exit(1); // exit from program
		}

		// input a row
		printf(" Enter %d row , total %d elements ", (i + 1), *pColumn);
		for (int j = 0; j < *pColumn; j++)
			scanf("%d", &(*pMatrix)[i][j]);
	}

}
void FreeMatrix(int*** pMatrix, int row) {
	for (int i = 0; i < row; i++) {
		free((*pMatrix)[i]);
		(*pMatrix)[i] = NULL;
	}
	free(*pMatrix);
	*pMatrix = NULL;
}
void PrintMatrix (int** matrix, int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++)
			printf("%4d", matrix[i][j]);
		printf("\n");
	}
}