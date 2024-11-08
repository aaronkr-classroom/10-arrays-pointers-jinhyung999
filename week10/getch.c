#include <stdio.h>
#include <conio.h>

int main() {
	char input_data;
	int count = 1;
	printf("Enter chars('q','Q',or ESC to quit)\n");
	while (1) {
		if (_kbhit()) {
			input_data = _getch();
			rewind(stdin);

			if (input_data == 'q' || input_data == 'Q' || input_data == 27) {
				printf("\nExiting program...\n");
				break;
			}
			printf("input %d :%c\n", count++, input_data);
		}
	}
}