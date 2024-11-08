//getc.c
#include <stdio.h>

int main() {
	//입력 문자가있으면 계속 읽고 출려하는 프로그램
	//@까지 읽을수 있다
	char ch;

	printf("Enter char to read(@ to stop):\n");

	while ((ch = getc(stdin)) != '@'){
		//받은 문자를 다시출력
		putchar(ch);
	}
	while (getc(stdin) != '@') {
		ch = getc(stdin);
	}
	printf("\nEndof input.\n");

	return 0;
}