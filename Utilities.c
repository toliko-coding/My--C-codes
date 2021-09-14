#define LEN 41
#include <stdio.h>
int StrLen(char[]);//Returns the amount of characters 
int StrCompare(char[],char[]);//Compares whether 2 strings are the same
void StrCopy(char[], char[]);//Copies string content one by one
void StrCat(char[], char[]);//String content from one string to another
int main() {
	char str1[LEN], str2[2*LEN];
	printf("Enter your string :");
	scanf("%s", str1);
	printf(" String length : %d\n", StrLen(str1));
	StrCopy(str2, str1);
	printf("%s\n", str2);
	if (!StrCompare(str1, str2))
		printf(" Same strings \n");
	else 
		printf("Strings not the same\n");
	StrCat(str2, str1);
	printf("%s\n", str1);
	printf("%s\n", str2);
	return 0;
}
int StrLen(char str[]) {
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
int StrCompare(char str1[],char str2[]) {
	int i = 0;
	while (str1[i] == str2[i]) {
		if (str1[i] == '\0') // or if(str2[i]== '\0')
			return 0;
		i++;
	}
	return str1[i] - str2[i];
}
void StrCopy(char str1[], char str2[]) {
	int i = 0;
	while (str2[i] != '\0') {
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
}
void StrCat(char str1[], char str2[]) {
	int i = 0, j = 0;
	while (str1[i] != '\0')
		i++;
	while (str2[j] != '\0')
		str1[i++] = str2[j++];
	str1[i] = '\0';
}

