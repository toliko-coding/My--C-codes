#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

void BuildMatrix(int***, int*, int*);
void FreeMatrix(int***, int);
void DelRow(int***, int*, int,int);
void PrintMatrix(int**, int, int);

int main() {
	int row, column, **matrix = NULL;
	// build matrix
	BuildMatrix(&matrix, &row, &column);
	// print all data 
	printf(" Before deleting ...\n");
	PrintMatrix(matrix, row, column);
	// delete the second row and update memory
	DelRow(&matrix, &row, column, 2);
	// print all data 
	printf(" After deleting ...\n");
	PrintMatrix(matrix, row, column);
	// Free
	FreeMatrix(&matrix, row);

	return 0;
}

void BuildMatrix(int*** pMatrix, int* pRow, int* pColumn) {
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
void PrintMatrix(int** matrix, int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++)
			printf("%4d", matrix[i][j]);
		printf("\n");
	}
}

void DelRow(int*** pMatrix, int* pRow, int column, int idRow) {
	int** help = *pMatrix;

	*pMatrix = (int**)malloc((*pRow-1) * sizeof(int*));
	if (*pMatrix == NULL) {
		printf(" Not enougth memory! ");
		FreeMatrix(&help, *pRow);
		exit(1); // exit from program
	}
	for (int i = 0, j=0; i < *pRow; i++) {
		if (i != (idRow - 1)) {
			(*pMatrix)[j] = help[i];
			j++;
		}
	}
	// update number of rows
	(*pRow)--;
	// free
	free(help[idRow - 1]);
	free(help);

}

// Another version
//void DelRow(int*** pMatrix, int* pRow, int column, int idRow) {
//	int** help = *pMatrix;
//	int** temp = *pMatrix;
//
//	temp = (int**)malloc((*pRow - 1) * sizeof(int*));
//	if (temp == NULL) {
//		printf(" Not enougth memory! ");
//		FreeMatrix(&help, *pRow);
//		exit(1); // exit from program
//	}
//	for (int i = 0, j = 0; i < *pRow; i++) {
//		if (i != (idRow - 1)) {
//			temp[j] = help[i];
//			j++;
//		}
//	}
//	// update number of rows
//	(*pRow)--;
//	// free
//	free(help[idRow - 1]);
//	free(help);
//
//	*pMatrix = temp;
//
//}