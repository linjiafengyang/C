#include <stdio.h>
int reverseDigits(int n);
int main() {
	int number;
	printf("Enter a number between 1 and 999999999:");
	scanf("%d", &number);
	printf("The number with its digits reversed is:%d\n", reverseDigits(number));
	return 0;
}
int reverseDigits(int n) {
	int reverse = 0;
	int divisor = 100000000;
	int multiplier = 1;
	while(n > 9) {
		if(n >= divisor) {
			reverse += n / divisor * multiplier;
			n %= divisor;
			divisor /= 10;
			multiplier *= 10;
		}
		else {
			divisor /= 10;
		}
	}
	reverse += n * multiplier;
	return reverse;
}
