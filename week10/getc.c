//getc.c
#include <stdio.h>

int main() {
	//�Է� ���ڰ������� ��� �а� ����ϴ� ���α׷�
	//@���� ������ �ִ�
	char ch;

	printf("Enter char to read(@ to stop):\n");

	while ((ch = getc(stdin)) != '@'){
		//���� ���ڸ� �ٽ����
		putchar(ch);
	}
	while (getc(stdin) != '@') {
		ch = getc(stdin);
	}
	printf("\nEndof input.\n");

	return 0;
}