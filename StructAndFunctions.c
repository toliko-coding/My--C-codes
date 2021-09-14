#define LEN 30
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Student { 
	char name[LEN];
	int id;
};


void InputStudent(struct Student*);
void PrintStudent(struct Student);
int FindIdMax(struct Student*, int);
int main()
{
	int i;
	printf("\n\n ------------------------------ Single variable structure    ---------------------------------------------------------\n");
	
	struct Student std;
	InputStudent(&std);
	PrintStudent(std);

	printf("\n\n ------------------------------ Array of  structures    ---------------------------------------------------------\n");

	struct Student arr[3];
	// insert data to array
	for (int i = 0; i < 3; i++) 
		InputStudent(&arr[i]); 
	

	//print all data 
	for (int i = 0; i < 3; i++) 
		PrintStudent(arr[i]);
	

	// Search for a student with a maximum id
	i = FindIdMax(arr, 3);
	PrintStudent(arr[i]);

	printf("\n\n ------------------------------ Dynamic array of  structures    ---------------------------------------------------------\n");

	struct Student* ptrStudent = NULL;
	int size;
	printf(" Enter the number of students:");
	scanf("%d", &size);
	ptrStudent = (struct Student*)malloc(size * sizeof(struct Student));
	if (ptrStudent == NULL) {
		printf("  Not enouth memory !");
		exit(1);
	}

	for (int i = 0; i < size; i++) {
		InputStudent(&ptrStudent[i]);
		PrintStudent(ptrStudent[i]);
	}

	free(ptrStudent);

}

void InputStudent(struct Student* ptrStudent) {
	printf(" Enter student's data : id and name :\n");
	scanf("%d %s", &ptrStudent->id, ptrStudent->name);//scanf("%d %s", &(*ptrStudent).id, (*ptrStudent).name);

}
void PrintStudent(struct Student stud) {
	printf(" Student's data :\n");
	printf(" id : %d , name : %s\n", stud.id, stud.name);
}

int FindIdMax(struct Student* ar, int size) {
	int index,maxIndex = 0;
	for (index = 1; index < 3; index++) {
		if (ar[index].id > ar[maxIndex].id)
			maxIndex = index;
	}
	return maxIndex; // return index
}

