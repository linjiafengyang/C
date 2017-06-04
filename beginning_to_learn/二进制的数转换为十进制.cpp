#include <stdio.h>
int main() {
	int binary;
	int number;
	int decimal = 0;
	int highbit = 16;
	int factor = 10000;
	printf("Enter a binary number(5 digits maximum):");
	scanf("%d", &binary);
	number = binary;
	while(highbit >= 1) {
		decimal += binary / factor *highbit;
		highbit /= 2;
		binary %= factor;
		factor /= 10;
	}
	printf("The decimal equilavent of %d is %d\n", number, decimal);
	return 0;
}

