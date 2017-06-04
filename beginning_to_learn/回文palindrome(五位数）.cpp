#include <stdio.h>
int main() {
	int number;
	int temp1, temp2;
	int firstDigit;
	int secondDigit;
	int fourthDigit;
	int fifthDigit;
	printf("Enter a five-digit number:");
	scanf("%d", &number);
	temp1 = number;
	firstDigit = temp1 / 10000;
	temp2 = temp1 % 10000;
	
	secondDigit = temp2 / 1000;
	temp1 = temp2 % 1000;
	
	temp2 = temp1 % 100;
	fourthDigit = temp2 / 10;
	temp1 = temp2 %10;
	fifthDigit = temp1;
	
	if(firstDigit = fifthDigit) {
		if(secondDigit == fourthDigit) {
			printf("%d is a palindrome\n", number);
		}
		else {
			printf("%d is not a palindrome\n", number);
		}
	}
	else {
		printf("%d is not a palindrome\n", number);
	}
	return 0;
} 

