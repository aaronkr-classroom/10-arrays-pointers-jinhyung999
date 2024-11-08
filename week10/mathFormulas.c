//mathFormulas.c
#include <stdio.h>
#include <stdlib.h> //atoi()�Լ��ִ� >>arrayToint() ���� �ۼ�
#include <ctype.h>// isdigit()>>numCheck() ���� �ۼ�

int numCheck(char ch) {
	return ch >= '0' && ch <= '9';// 1or0 ��ȯ
}

int checkOp(char op) {
	return op == '+' || op == '-' || op == '*' || op == '/';
}

int arrayToint(char str[]) {
	int i = 0,
		num = 0;

	//���ڿ��� �ݺ��ϰ� ��� ���ڰ� ���ڷ� �����ϱ�
	while (str[i] != '\0') {
		//�������� Ȯ��
		if (numCheck(str[i])) {//1
			num = num * 10 + (str[i] - '0');//ASCII 48���� ��Ǽ��ڷ� ����
		}
		else{//0
			break;
		}
		i++;//�������ڷ� �̵�
	}
	return num;
}

int main(void) {
	char input[100],
		numStr1[50], numStr2[50],
		operator='\0';
	int i = 0, 
		j = 0;

	//����ڿ��� �����Լ��ޱ�(ex:"12+34")
	printf("Enter a simple math formula (12+34)\n");
	fgets(input, sizeof(input), stdin);
	
	//ù��°���ڸ� �����ϱ�
	while (input[i] != '\0' && numCheck(input[i])) {
		numStr1[j++] = input[i++];
	}
	numStr1[j] = '\0';

	//���� �����ڸ� ã��
	if (checkOp(input[i])) {
		operator=input[i++];
	}
	else {
		printf("Error: Invalid operator!\n");
		return 1;
	}
	j = 0;
	while (input[i] != '\0' && numCheck(input[i])) {
		numStr2[j++] = input[i++];
	}
	numStr2[j] = '\0';

	int num1 = arrayToint(numStr1);
	int num2 = arrayToint(numStr2);
	int result = 0;

	//����ϱ�
	switch (operator) {
	case'+':
		result = num1 + num2;
		break;
	case'-':
		result = num1 - num2;
		break;
	case'*':
		result = num1 * num2;
		break;
	case'/':
		if (num2 != 0)
			result = num1 / num2;
		else{
			printf("Error: division by 0!\n");
			return 1;
		}
		break;
	default:
		printf("Error: Invalid operator. Use +,-,*,/\n");
		return 1;
	}

	printf("Result:%d %c %d=%d\n", num1, operator,num2, result);

	return 0;
}