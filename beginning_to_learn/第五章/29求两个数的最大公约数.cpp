#include <stdio.h>
int gcd(int x, int y);
int main() {
	int j, a, b;
	for(j = 1; j <= 3; j++) {
		printf("Enter two integers:");
		scanf("%d%d", &a, &b);
		printf("The greatest common divisor of %d and %d is %d\n", a, b, gcd(a,b));
	}
	return 0;
}
int gcd(int x, int y) {
	int i;
	int greatest = 1;
	for(i = 2; i <= ((x < y) ? x : y); i++) {
		if(x % i == 0 && y % i == 0) {
			greatest = i;
		}
	}
	return greatest;
}
