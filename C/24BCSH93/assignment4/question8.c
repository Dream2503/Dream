#include <stdio.h>

int main() {
	int num1, num2, res;
	char opr;
	printf("Enter the expression with operands and operator: ");
	scanf("%d %c%d", &num1, &opr, &num2);

	switch (opr) {
		case '+':
			res = num1 + num2;
			break;
		case '-':
			res = num1 - num2;
			break;
		case '*':
			res = num1 * num2;
			break;
		case '/':
			res = num1 / num2;
			break;
		default:
			printf("Invalid operator\n");
	}
	printf("Result = %d\n", res);
	return 0;
}