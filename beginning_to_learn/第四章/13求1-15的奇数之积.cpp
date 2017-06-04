#include <stdio.h>
int main() {
	long i;
	long product = 1;
	for(i = 3; i <= 15; i += 2) {
		product *= i;
	}
	printf("Product of the odd integers from 1 to 15 is: %d", product);
	return 0;
}
