//getMyString.c
#include <stdio.h>

#define MAX_CH 20

int getMyString(char buffer[], int limit);

int main(void) {
	char input_string[MAX_CH];
	int state;//사용자에게 최대 MAX_CH까지만 입력 받겠다고 제한함

	state = getMyString(input_string, MAX_CH);

	if (state)printf("input: %s\n", input_string);
	else printf("input: %s -> out of range\n", input_string);
}

int getMyString(char buffer[], int limit) {
	int i;
	for (i = 0; i < limit; i++) {
		buffer[i] = getchar();
		if (buffer[i] == '\n') {
			buffer[i] = 0;
			return 1;
		}
	}
	buffer[i] = 0;
	rewind(stdin);
	return 0;
}

void isCanceled(char input_string[]) {
		if (NULL != gets(input_string)) {
			printf("input: %s\n", input_string);
		}
		else {
			printf("input->Canceled!\n");
		}
}