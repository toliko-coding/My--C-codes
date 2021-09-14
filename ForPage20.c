#define LEN 9
#define DIFF 'b'-'B'
#include <stdio.h>

typedef enum { False, True } Bool;
int StrLen(char[]);//Returns the amount of characters 
Bool isUpper(char);//Checks whether a character is a large letter
Bool isLower(char);//Checks whether a character is a small letter
void UpdateString(char[]);//The function updates a string
int StrCompare(char[], char[]);//Compares whether 2 strings are the same

int main() {
	char name[LEN];
	printf("Enter your string :");
	scanf("%s",name);
	printf("%s, string length :%d\n", name , StrLen(name));
	UpdateString(name);
	printf(" After update :%s\n", name);
	if (StrCompare(name, "Avi")==0)
		printf("The name is Avi");
	else 
		printf("The name is not Avi");
	return 0;
}
int StrLen(char str[]) {
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}
Bool isUpper(char letter) {
	return letter >= 'A' && letter <= 'Z';
}
Bool isLower(char letter) {
	return letter >= 'a' && letter <= 'z';
}
void UpdateString(char str[]) {
	int i = 1;
	if (isLower(str[0]) )
		str[0] -= DIFF;
	while (str[i] != '\0') {
		if (isUpper(str[i]))
			str[i] += DIFF;
		i++;
	}
}
int StrCompare(char str1[], char str2[]) {
	int i = 0;
	while (str1[i] == str2[i]) {
		if (str1[i] == '\0') // or if(str2[i]== '\0')
			return 0;
		i++;
	}
	return str1[i] - str2[i];
}
