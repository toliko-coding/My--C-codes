/* Search in  array */
#include<stdio.h>
#define SIZE 3
typedef enum { False, True} Boolean;

void InputMatrix(int[][SIZE]);
void PrintMatrix(int[][SIZE]);
long SumMatrix(int[][SIZE]);
Boolean CheckMatrix(int[][SIZE]);

int CountAppearsForValue(int [][SIZE],int );
int CommonElement(int[][SIZE]);

int main(){
	int matrix[SIZE][SIZE];
    InputMatrix(matrix);
    PrintMatrix(matrix);

    printf("Sum of Elements : %ld \n",SumMatrix(matrix) );

    printf(" Common element is %d \n",CommonElement(matrix) );

	if( CheckMatrix (matrix) == True)
        printf(" Normal Matrix\n ");
    else
        printf(" Invalid Matrix\n ");
	return 0;
}
void InputMatrix(int mat[][SIZE]){
    /* Fill in a matrix with values*/
    printf("Please enter %d elements" , SIZE*SIZE);
    for(int i=0; i<SIZE ; i++)
        for(int j=0; j<SIZE ; j++)
            scanf("%d",&mat[i][j]);

}
void PrintMatrix(int mat [][SIZE]){
    /* Print matrix in the table form*/
     printf("The matrix :\n");
    for(int i=0; i<SIZE ; i++){
        for(int j=0; j<SIZE ; j++)
            printf("%4d",mat[i][j]);
        printf("\n");
    }
        
}
long SumMatrix(int mat[][SIZE]){
    /* Find the sum of matrix */
    long sum=0;
    for(int i=0; i<SIZE ; i++)
        for(int j=0; j<SIZE ; j++)
            sum+=mat[i][j];
    return sum;
}
Boolean CheckMatrix(int mat [][SIZE]){
    /* Check if the main diagonal sum is equal to the secondary diagonal sum*/
    int sumMainDiag=0,sumSecDiag=0;
    for(int i=0;i<SIZE;i++){
        sumMainDiag+=mat[i][i];
        sumSecDiag+=mat[i][SIZE-1-i];
    }
    return sumMainDiag == sumSecDiag;
}


int CommonElement(int mat[][SIZE]){
    /* return the most common element in the matrix*/
    int common=mat[0][0],count=0,maxCount=0;
    for(int i=0; i<SIZE ; i++)
        for(int j=0; j<SIZE ; j++){
            count= CountAppearsForValue(mat,mat[i][j]);
            if(count>maxCount){
                maxCount=count;
                common=mat[i][j];
            }
        }
    return common;
}
int CountAppearsForValue(int mat[][SIZE],int value){
    int count=0;
    for(int i=0; i<SIZE ; i++)
        for(int j=0; j<SIZE ; j++)
            if( mat[i][j]==value)
                count++;

    return count;
}
