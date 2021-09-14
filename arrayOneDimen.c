#include<stdio.h>
#define SIZE 5
void InputData(int[]);
void PrintData(int[]);
long SumElements(int[]);
long MaxElement(int[]);
long SumMultiply(int[]);
int main(){
	int arr[SIZE], max;

	InputData(arr);
	PrintData(arr);
	max=MaxElement(arr);
	printf(" sum of elements is : %ld , max element is : %d\n",
	SumElements(arr),max);
	printf(" sum of multiply : %ld\n",SumMultiply(arr));
	return 0;
}
void InputData(int ar []){
	printf(" Please enter data :\n");
	for(int i=0;i<SIZE;i++){
		printf("[%d] element :", i+1);
		scanf("%d",&ar[i]);
	}
	
}
void PrintData(int arr[]){
	for(int i=0;i<SIZE;i++)
		printf("%d ",arr[i]);
	printf("\n");

}
long SumElements(int array[]){
	long sum=0;
	for(int i=0;i<SIZE;i++)
		sum+=array[i];
	return sum;

}
long MaxElement(int ar[]){
	int max=ar[0];
	for(int i=1;i<SIZE;i++)
		if(ar[i] > max )
			max=ar[i];
	return max;
}
long SumMultiply(int array[]){
	long sum=0;
	for(int i=0;i<SIZE;i++)
		sum+=array[i] * i;
	return sum;

}
