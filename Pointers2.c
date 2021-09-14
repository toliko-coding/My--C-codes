#include <stdio.h>

//A function accepts an array, including its size and returns the amount of even and the amount of odd elements
int EvenOddArray(int[], int, int*);
void UpdateValue(int*);
int main()
{
	int arr[] = { 1,2,3,4,5,7 }, even = 0, odd = 0, size = sizeof(arr) / sizeof(int), value=10;
	even = EvenOddArray(arr, size, &odd);
	printf("\namount of even elements : %d  and amount of odds :%d\n", even, odd); // main : Before SwapByValue : 4 10
	UpdateValue(&value);
	printf("%d\n", value);
	return 0;
}
int EvenOddArray(int ar[], int total, int* ptrOdd) {
	int even = 0;
	*ptrOdd = 0;
	for (int i = 0; i < total; i++) {
		if (ar[i] % 2 == 0)
			even++;
		else
			(*ptrOdd)++;//Brackets are a must here!
	}
	return even;
}

void UpdateValue(int* val) {
	*val *= 2;
}