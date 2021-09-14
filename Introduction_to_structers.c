#define LEN 30
#include <stdio.h>
#include <string.h>

struct Student { //---------------------- type      struct Student
	char name[LEN];
	int id;
};
//typedef struct {//---------------------- type      Student
//	char name[LEN];
//	int id;
//}Student;

int main()
{
	printf("\n\n ------------------------------ Single variable structure    ---------------------------------------------------------\n");
	// primitive data type :
	int x, y, *ptr = NULL;
	ptr = &x;
	*ptr = 10;  //x=10
	ptr = &y;
	*ptr = 20;  // y=20
	// Structures :
	struct Student std1, std2, *ptrSt = NULL; // or Student std1, std2, *ptrSt = NULL;
	std1.id = 100;
	strcpy(std1.name, " Rut");
	printf(" Data of std1 id: %d , name : %s \n", std1.id, std1.name);//Data of std1 id: 100 , name : Rut

	printf(" Enter std1's data : id and name :\n");
	scanf("%d %s", &std1.id, std1.name);//200 David
	printf(" Data of std1 id: %d , name : %s \n", std1.id, std1.name);//Data of std1 id: 200 , name : David

	ptrSt = &std2; // initialization of pointer to structer
	(*ptrSt).id = 100; // or ptr->id=100;
	strcpy((*ptrSt).name, " Rut");//strcpy(ptrSt->name, " Rut");
	printf(" Data of std2 id: %d , name : %s \n", ptrSt->id, ptrSt->name);//Data of std2 id: 100 , name : Rut
	printf(" Data of std2 id: %d , name : %s \n", std2.id, std2.name);//Data of std2 id: 100 , name : Rut

	printf("\n\n ------------------------------ Array of  structures    ---------------------------------------------------------\n");

	struct Student arr[3];
	// insert data to array
	for (int i = 0; i < 3; i++) {
		printf(" Enter student's # %d data : id and name :\n", i+1);
		scanf("%d %s", &arr[i].id, arr[i].name);
	}

	//print all data 
	for (int i = 0; i < 3; i++) {
		printf(" Student's # %d data :\n", i + 1);
		printf(" id : %d , name : %s\n", arr[i].id, arr[i].name);
	}

	// Search for a student with a maximum id
	int maxIndex=0;
	for (int i = 1; i < 3; i++) {
		if (arr[i].id > arr[maxIndex].id)
			maxIndex = i;
	}
	printf("\n Student with a maximum id : id : %d , name : %s\n", arr[maxIndex].id, arr[maxIndex].name);

	printf("\n\n ------------------------------ Array of  structures    ---------------------------------------------------------\n");

}

