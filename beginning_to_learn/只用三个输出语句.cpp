#include <stdio.h>
int main() {
	int side = 8;
	int row;
	int mod;
	while(side >= 1) {
		row = 8;
		mod = side % 2;
		while(row >= 1) {
			if(mod != 0) {
				printf(" ");
			    mod = 0;   /*╫одя*/	
			}
			printf("* ");
			--row;
		}
		printf("\n");
		--side;
	}
	return 0;
} 

