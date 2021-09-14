#define SIZE 41
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void BuildText(char***,int*);
void FreeText(char***, int);
void PrintText(char**, int);
void SortText(char**, int);

int main()
{
	char** text = NULL;
	int countOfWords;
	BuildText(&text, &countOfWords);

	printf(" \nBefore sorting :\n");
	PrintText(text, countOfWords);

	printf(" \nAfter sorting :\n");
	SortText(text, countOfWords);
	PrintText(text, countOfWords);

	//free memory
	FreeText(&text, countOfWords);
	return 0;

}

void BuildText(char*** pText, int* pCount) {
	int i;
	char helpBuffer[SIZE];
	printf(" Enter the number of words :\n");
	scanf("%d", pCount);
	// dynamic allocation
	*pText = (char**)calloc(*pCount, sizeof(char*));

	if (*pText == NULL) {
		printf(" Not enougth memory!");
		exit(1);
	}
	printf(" Enter %d words :\n",*pCount);
	for (i = 0; i < *pCount; i++) {
		scanf("%s", helpBuffer);
		(*pText)[i] = (char*)malloc(strlen(helpBuffer) + 1); //+1 for '\0'
		if ((*pText)[i] == NULL) {
			printf(" Not enougth memory!");
			FreeText(pText, i);
			exit(1);
		}
		strcpy((*pText)[i], helpBuffer);
	}
}
void FreeText(char*** pText, int count) {
	for (int i = 0; i < count; i++)
		free((*pText)[i]);
	free(*pText);
}
void PrintText(char** text, int count) {
	for (int i = 0; i < count; i++)
		printf("%s\n", text[i]);
}
void SortText(char** text, int count) { // Bubble sort - ascending 
	int  flag;
	char* temp;
	do {
		flag = 0;
		for(int i=0;i< count -1 ;i++)
			if (strcmp(text[i], text[i + 1]) > 0 ) {
				temp = text[i];
				text[i] = text[i + 1];
				text[i + 1] = temp;
				flag = 1;
			}

	} while (flag==1);
}
