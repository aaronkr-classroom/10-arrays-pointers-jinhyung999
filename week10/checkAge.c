//checkAge.c
#include <stdio.h>

int main() {
	int age = 0;

	//�������� ���̸� �Է��Ҷ����� �ݺ��ϱ�
	while (1) {
		printf("Input age: ");
		//scnaf�Լ��� ���࿡ �����ϸ� 0�� ��ȯ�մϴ�
		if (!scanf_s("%d", &age)) {
			rewind(stdin); // �ּ� ����� ���ѹݺ���
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