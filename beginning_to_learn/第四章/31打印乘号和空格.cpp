#include <stdio.h>
int main() {
	int line;
	int space;
	int asterisk;
	for(line = 1; line <= 9; line += 2) {
		for(space = (9 - line) / 2; space > 0; space--) {
			printf(" ");
		}
		for(asterisk = 1; asterisk <= line; asterisk++) {
			printf("*");
		}
		printf("\n");
	}
	for(line = 7; line >= 0; line -= 2) {
		for(space = (9 - line) / 2; space > 0; space--) {
			printf(" ");
		}
		for(asterisk = 1; asterisk <= line; asterisk++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
