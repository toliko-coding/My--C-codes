#include <stdio.h>

int Sum(int[], int);
//Scanning the array with a pointer
int SumPointer(int*, int);

int main()
{
	int arr[] = { 1,2,3,4,5,7 }, size = sizeof(arr) / sizeof(int), total;
	total = Sum(arr, size);
	printf("\nsum of elements : %d \n", total);
	total = SumPointer(arr, size);
	printf("\nsum of elements : %d \n", total);
	return 0;
}
int Sum(int ar[], int size) {
	int tot = 0;
	for (int i = 0; i < size; i++)
		tot += ar[i];
	return tot;
}

int SumPointer(int* ar, int size) {
	int *end, tot = 0;
	end = ar + size;
	while (ar < end) {
		tot += *ar;
		ar++;
	}
	return tot;
}
