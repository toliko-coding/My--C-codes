#include <stdio.h>
int FactorialIterative(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++)
		result *= i;
	return result;
}

int FactorialRecursive(int n) {
	if (n == 0) // base case
		return 1;
	else  // recursive call
		return n * FactorialRecursive(n - 1);
}

int PowerIterative(int base, int exp) {
	int result = 1;
	for (int i = 1; i <= exp; i++)
		result *= base;
	return result;
}

int PowerRecursive(int base, int exp) {
	if (exp == 0) // base case
		return 1;
	else  // recursive call
		return base * PowerRecursive(base,exp - 1);
}

int Fibbonachi(int n) {
	if (n < 0)
		return - 1;
	if (n <= 1)
		return 1;
	else
		return Fibbonachi(n - 1) + Fibbonachi(n - 2);
	
}
long SumDigits(long number) {
	if (number == 0)
		return 0;
	else return number % 10 + SumDigits(number / 10);
}

int SumArray(int* ar, int size) {
	if (size == 0)
		return 0;
	else
		return ar[size - 1] + SumArray(ar, size - 1);
}

//int SumArray(int* ar, int size) {
//	if (size == 0)
//		return 0;
//	else
//		return ar[0] + SumArray(ar+1, size - 1);
//}

int MaxArray(int* ar, int size) {
	int rest;
	if (size == 1)
		return ar[0];
	else {
		rest = MaxArray(ar + 1, size - 1);
		if (ar[0] > rest)
			return ar[0];
		else
			return rest;
	}//else
}// end MaxArray

//int MaxArray(int* ar, int size) {
//	int rest;
//	if (size == 1)
//		return ar[size-1];
//	else {
//		rest = MaxArray(ar , size - 1);
//		if (ar[size-1] > rest)
//			return ar[size-1];
//		else
//			return rest;
//	}//else
//}// end MaxArray

int strLen(char* str) {
	if (*str == '\0')
		return 0;
	else
		return 1 + strLen(str + 1);

}
void strCopy(char* target, char* source) {
	*target = *source;
	if (*source)
		strCopy(target + 1, source + 1);
}
int main()
{
	int arr[] = { 1,4,9,6 }, size = sizeof(arr) / sizeof(int);
	char str1[] = "abcd", str2[10];


	printf("\n Factorial :\n");
	printf("%d %d\n", FactorialIterative(4), FactorialRecursive(4)); // 24 24
	printf("\n Power :\n");
	printf("%d %d\n", PowerIterative(2,3), PowerRecursive(2,3));// 8 8

	printf("\n Fibbonachi :\n");
	printf("%d %d\n", Fibbonachi(3), Fibbonachi(5));// 3 8

	printf("\n Sum of digits : 1234 :\n");
	printf("%ld \n", SumDigits(1234));//10

	printf("\n Sum of array :\n");
	printf("%ld \n", SumArray(arr,size));//20

	printf("\n Max element of array :\n");
	printf("%ld \n", MaxArray(arr, size));//9

	printf("\n Strings :\n");

	strCopy(str2, str1);
	printf("%s %s\n", str1, str2);//abcd abcd
	printf("The length : %d\n", strLen(str1));// The length : 4
}

