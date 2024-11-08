//mathFormulas.c
#include <stdio.h>
#include <stdlib.h> //atoi()함수있다 >>arrayToint() 직접 작성
#include <ctype.h>// isdigit()>>numCheck() 직접 작성

int numCheck(char ch) {
	return ch >= '0' && ch <= '9';// 1or0 반환
}

int checkOp(char op) {
	return op == '+' || op == '-' || op == '*' || op == '/';
}

int arrayToint(char str[]) {
	int i = 0,
		num = 0;

	//문자열에 반복하고 모든 문자가 숫자로 변경하기
	while (str[i] != '\0') {
		//숫자인지 확인
		if (numCheck(str[i])) {//1
			num = num * 10 + (str[i] - '0');//ASCII 48빼고 사실숫자로 변경
		}
		else{//0
			break;
		}
		i++;//다음문자로 이동
	}
	return num;
}

int main(void) {
	char input[100],
		numStr1[50], numStr2[50],
		operator='\0';
	int i = 0, 
		j = 0;

	//사용자에게 수학함수받기(ex:"12+34")
	printf("Enter a simple math formula (12+34)\n");
	fgets(input, sizeof(input), stdin);
	
	//첫번째숫자를 추출하기
	while (input[i] != '\0' && numCheck(input[i])) {
		numStr1[j++] = input[i++];
	}
	numStr1[j] = '\0';

	//수학 연산자를 찾기
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

	//계산하기
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