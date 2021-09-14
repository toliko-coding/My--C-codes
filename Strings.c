#define SIZE 41
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* CreateString1();
void CreateString2(char**);
int main()
{
	char* str = NULL;
	str=CreateString1();
	printf(" You enter : %s\n", str);
	free(str);
	
	
	CreateString2(&str);
	printf(" You enter : %s\n", str);
	free(str);
}

char* CreateString1() {
	char *str,temp[SIZE];
	printf("\nEnter your string :");
	scanf("%s", temp);
	str = (char*)malloc(strlen(temp) + 1);
	if (str == NULL) {
		printf(" Not enoutg memory! ");
		exit(1);
	}
	strcpy(str, temp);
	return str;
}

void CreateString2(char** pStr) {
	char temp[SIZE];
	printf("\nEnter your string :");
	scanf("%s", temp);
	*pStr = (char*)malloc(strlen(temp) + 1);
	if (*pStr == NULL) {
		printf(" Not enoutg memory! ");
		exit(1);
	}
	strcpy(*pStr, temp);
}
