#include <stdio.h>
int main() {
	int side;
	int size;
	int rowPosition;
	printf("Enter the square side:");
	scanf("%d", &side);
	size = side;
	while(side > 0) {
		rowPosition =size;
		while(rowPosition > 0) {
			if(size == side) {
				printf("*");
			}
			else if(side == 1) {
				printf("*");
			}
			else if(rowPosition == 1) {
				printf("*");
			}
			else if(rowPosition == size) {
				printf("*");
			}
			else {
				printf(" ");
			}
			--rowPosition;
		}
		printf("\n");
		--side;
	}
	return 0;
}

