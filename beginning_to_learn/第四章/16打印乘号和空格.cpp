#include <stdio.h>
int main() {
	int row;
	int col;
	int space;
	for(row = 1; row <= 10; row++) {
		for(col = 1; col <= row; col++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	
	for(row = 10; row >= 1; row--) {
		for(col = 1; col <= row; col++) {
			printf("*");
		} 
		printf("\n");
	}
	printf("\n");
	
	for(row = 10; row >= 1; row--) {
		for(space = 1; space <= 10 - row; space++) {
			printf(" ");
		}
		for(col = 1; col <= row; col++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
	
	for(row = 1; row <= 10; row++) {
		for(space = 1; space <= 10 - row; space++) {
			printf(" ");
		}
		for(col = 1; col <= row; col++) {
			printf("*");
		}
		printf("\n");
	}
	printf("\n");
} 
