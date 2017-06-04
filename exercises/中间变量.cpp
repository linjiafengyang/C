#include <stdio.h>
int main() {
	int side;
	int temp;
	int asterisk;
	printf("Enter the square side:");
	scanf("%d", &side);
	temp = side;
	while(side-- > 0) {
		asterisk = temp;
		while(asterisk-- > 0) {
			printf("*");
		}
		putchar('\n');
	}
	return 0;
}

