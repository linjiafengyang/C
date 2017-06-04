#include <stdio.h>
long power(long base, long exponent);
int main() {
	long b;
	long e;
	printf("Enter a base and an exponent:");
	scanf("%ld%ld", &b, &e);
	printf("%ld raised to the %ld is %ld\n", b, e, power(b, e));
	return 0;
}
long power(long base, long exponent) {
	if(exponent == 1) {
		return base;
	}
	else {
		return base * power(base, exponent - 1);
	}
}
