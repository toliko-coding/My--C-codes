
#include <stdio.h>
void SwapByValue(int , int );
void SwapByPointer(int*, int*);
int main()
{
	int a = 4, b = 10;
	printf("\nmain : Before SwapByValue :%d %d\n", a, b); // main : Before SwapByValue : 4 10
	SwapByValue(a, b);
	printf("\nmain : After SwapByValue :%d %d\n", a, b);//main : After SwapByValue : 4 10
	printf("\nmain : Before SwapByPointer :%d %d\n", a, b);//main : Before SwapByPointer :4 10
	SwapByPointer(&a, &b);
	printf("\nmain : After SwapByPointer :%d %d\n", a, b);//main : After SwapByPointer :10 4
	return 0;
}
void SwapByValue(int x, int y) {
	int temp;
	printf("\nInside SwapByValue : Before swap :%d %d\n", x, y);//Inside SwapByValue : Before swap :4 10
	temp = x;
	x = y;
	y = temp;
	printf("\nInside SwapByValue :After swap :%d %d\n", x, y);//Inside SwapByValue :After swap :10 4

}
void SwapByPointer(int* ptrA, int* ptrB) {
	int temp;
	printf("\nInside SwapByPointer : Before swap :%d %d\n", *ptrA, *ptrB);//Inside SwapByPointer : Before swap :4 10
	temp = *ptrA;
	*ptrA = *ptrB;
	*ptrB = temp;
	printf("\nInside SwapByPointer : After swap :%d %d\n", *ptrA, *ptrB);//Inside SwapByPointer : After swap :10 4
}
