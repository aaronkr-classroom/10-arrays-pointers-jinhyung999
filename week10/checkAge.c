//checkAge.c
#include <stdio.h>

int main() {
	int age = 0;

	//정상적인 나이를 입력할때까지 반복하기
	while (1) {
		printf("Input age: ");
		//scnaf함수는 실행에 실패하면 0을 반환합니다
		if (!scanf_s("%d", &age)) {
			rewind(stdin); // 주석 지우면 무한반복됨
			printf("Only digits allowed!\n");
		}
		else {
			if (age > 0 && age <= 130) {
				break;
			}
			else
			{
				printf("Incorrect age! Try again\n");
			}
		}
	}
	printf("Your age: %d\n", age);

	return 0;
}