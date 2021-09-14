#define SIZE 41
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int i, count;
	char helpBuffer[SIZE],**text = NULL;
	printf(" Enter the number of words :\n");
	scanf("%d", &count);
	// dynamic allocation
	text = (char**)calloc(count, sizeof(char*));

	if (text == NULL) {
		printf(" Not enougth memory!");
		exit(1);
	}

	for ( i = 0; i < count; i++) {
		scanf("%s", helpBuffer);
		text[i] = (char*)malloc(strlen(helpBuffer) + 1); //+1 for '\0'
		if (text[i] == NULL) {
			printf(" Not enougth memory!");
			for (int k = 0; k < i; k++)
				free(text[k]);
			free(text);
			exit(1);
		}
		strcpy(text[i], helpBuffer);
	}
	
	// print all text
	printf(" You entered :\n");
	for ( i = 0; i < count; i++)
		printf("%s\n", text[i]);

    // free memory
	for ( i = 0; i < count; i++)
		free(text[i]);
	free(text);
}

