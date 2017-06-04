#include <stdio.h>
int main() {
	int line;
	int space;
	int asterisk;
	int size;
	scanf("%d", &size); 
	for(line = 1; line <= size; line += 2) {
		for(space = (size - line) / 2; space > 0; space--) {
			printf(" ");
		}
		for(asterisk = 1; asterisk <= line; asterisk++) {
			printf("*");
		}
		printf("\n");
	}
	for(line = size - 2; line >= 0; line -= 2) {
		for(space = (size - line) / 2; space > 0; space--) {
			printf(" ");
		}
		for(asterisk = 1; asterisk <= line; asterisk++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
