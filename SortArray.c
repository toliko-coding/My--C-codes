/* Buble sort of array */
#include<stdio.h>
#define SIZE 5
typedef enum { False, True} Boolean;
void SortArray(int[],int);
void PrintData(int[],int);


int main(){
	int arr[]={4,3,1,2};
	int size=sizeof(arr)/sizeof(int);
	printf(" array BEFORE sorting :\n");
	PrintData(arr,size);
	SortArray(arr,size);
	printf(" array AFTER sorting :\n");
	PrintData(arr,size);
	
	return 0;
}
void SortArray(int ar [],int size){
	Boolean flag = False;
	int temp;
	do{
		flag = False;
		for(int i=0;i<size-1;i++)
			if(ar[i]>ar[i+1]){ // previous element is larger than the next
				temp=ar[i];
				ar[i]=ar[i+1];
				ar[i+1]=temp;
				flag=True; // replacement between neighbors
			}//if
	
		
	}while(flag == True);

}

void PrintData(int arr[], int size){
	for(int i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");

}

