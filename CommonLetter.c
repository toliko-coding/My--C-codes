#define LEN 61
#include <stdio.h>

typedef enum {False,True} Bool;
int StrLen(char[]);//Returns the amount of characters 
Bool isUpper(char);//Checks whether a character is a large letter
Bool isLower(char);//Checks whether a character is a small letter
char CommonLetter(char[]);//Returns a character that appears in the string most times

int main() {
	char str[LEN];
	printf("Enter your string :");
	fgets(str, LEN, stdin);
	//clear '\n
	int len = StrLen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
	printf(" a character that appears in the string most times is: %c \n", CommonLetter(str));
	
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
char CommonLetter(char str[]) {
	int counters[26] = { 0 };//Counter, will count the number of impressions each character in the string
	int i = 0, maxIndex;
	while (str[i] != '\0') {
		if (isUpper(str[i]))
			counters[str[i] - 'A'] += 1;
		if (isLower(str[i]))
			counters[str[i] - 'a'] += 1;
		i++;
	}
	//max search
	maxIndex = 0;
	for (i = 1; i < 26; i++)
		if (counters[i] > counters[maxIndex])
			maxIndex = i;
	return 'a' + maxIndex;
}

