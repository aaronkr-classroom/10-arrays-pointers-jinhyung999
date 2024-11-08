#include <stdio.h>

#define MAX_CHAR 50

int main() {
	char input_str[MAX_CHAR];

	printf("Enter your English name: \n");

	fgets(input_str, MAX_CHAR, stdin);

	printf("Name:%s\n", input_str);

	return 0;
}
