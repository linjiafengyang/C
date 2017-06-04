#include <stdio.h>
int main() {
	int number;
	int numcopy;
	int factor = 10000;
	int digit;
	int sevens = 0;
	printf("Enter a 5-digit number:");
	scanf("%d", &number);
	numcopy = number;
	while(factor >= 1) {
		digit = numcopy / factor;
		if(digit == 7){
			++sevens;
		}
		numcopy %= factor;
		factor /= 10;
	}
	printf("The number %d has %d seven(s) in it\n", number, sevens);
	return 0;
} 

