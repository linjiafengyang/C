#include <stdio.h>
unsigned int gcd(unsigned int x, unsigned int y);
int main() {
	unsigned x, y, gcDIV;
	scanf("%u%u", &x, &y);
	gcDIV = gcd(x, y);
	printf("Greatest common divisor of %u and %u is %u\n", x, y, gcDIV);
	return 0;
}
unsigned int gcd(unsigned int x, unsigned int y) {
	if(y == 0) {
		return x;
	}
	else {
		return gcd(y, x % y);
	}
}
