#include <stdio.h>
int main() {
	int side;
	int asterisk;
	printf("Enter the square side:");
	scanf("%d", &side);
	while(side >= 0) {
		asterisk = side;
		while(asterisk-- > 0) {
			printf("*");
		}
		side--;
		putchar('\n');
	}
	return 0;
}

