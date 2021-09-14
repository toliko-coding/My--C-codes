#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
/********** Function's declaration *****************/
void InitArray(int*, int);
int* CreateArray1(int*);
void CreateArray2(int**, int*);
void PrintArray(int*, int);
void FreeArray(int**);
/****************************************************/
int main(){
	int *pointer, sizeArray;
	pointer = NULL;
	sizeArray = 0;
	pointer = CreateArray1(&sizeArray);
	/*CreateArray2(&pointer, &sizeArray);*/
	PrintArray(pointer, sizeArray);
	FreeArray(&pointer);
	return 0;
}
/*********** Create Dynamic array *******************/
int* CreateArray1(int* size){
	int* ptr;
	printf("Enter a size of array :");
	scanf("%d", size);
	ptr = (int*)malloc(sizeof(int)*(*size));
	if (ptr == NULL){
		printf("Error - unable to allocate required memory\n");
		exit(1);
	}
	InitArray(ptr, *size);
	return ptr;
}

void CreateArray2(int** arr, int* size){
	printf("Enter a size of array :");
	scanf("%d", size);
	*arr = (int*)malloc(sizeof(int)*(*size));
	if (*arr == NULL){
		printf("Error - unable to allocate required memory\n");
		exit(1);
	}
	InitArray(*arr, *size);
}
/************ Array initialization  ******************/
void InitArray(int* ar, int size){
	int i;
	for (i = 0; i < size; i++){
		printf("Enter a [%d] element :", i + 1);
		scanf("%d", &ar[i]);
	}

}
/*********** Print array *******************/
void PrintArray(int* ar, int size){
	int i;
	for (i = 0; i < size; i++)
		printf("%4d", ar[i]);
	printf("\n");
}
/************ Free memory ******************/
void FreeArray(int** arr){
	free(*arr);
	*arr = NULL;
}