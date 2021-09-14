/* Search in  array */
#include<stdio.h>
#define NOT_FOUND -1

/*  Serial Search in unordered array  */
int FindElement(int[],int,int);

/* Binary  Search in  sorted  array in ascending order */
int Middle(int,int);
int BinarySearch(int [],int,int,int,int);


int main(){
	int array1[]={4,3,1,2} , array2[]={10,30,50,60,70,80};
	int size1=sizeof(array1)/sizeof(int) , size2=sizeof(array2)/sizeof(int) , index;

    index=FindElement(array1,size1,2);

    if ( index == NOT_FOUND)
    	printf(" This element does not exist :\n");
    else
        printf("This element %d is in  %d-th place\n",array1[index],index );

  index=BinarySearch(array2,size2,70,0,size2-1);

    if ( index == NOT_FOUND)
    	printf(" This element does not exist :\n");
    else
        printf(" This element %d is in  %d-th place\n",array2[index],index );

	
	
	return 0;
}
int FindElement(int arr[],int size ,int find){
	for(int i=0;i<size;i++)
			if( arr[i] == find)
                return i;
    return NOT_FOUND;
		
}

int MiddleCalculate(int start ,int end){
    return (start+end)/2;

}
int BinarySearch(int arr[],int size,int find ,int indexLeft,int indexRight){
    
    while( indexLeft <= indexRight){
        int indexMiddle=MiddleCalculate(indexLeft,indexRight);

    
        if(arr[indexMiddle] == find)
            return indexMiddle;
        else if (arr[indexMiddle] > find) // Search in the left part
                indexRight=indexMiddle-1;
        else
            indexLeft=indexMiddle+1; // Search in the right part

    }
    return NOT_FOUND;
}

