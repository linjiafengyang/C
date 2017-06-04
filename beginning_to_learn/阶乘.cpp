#include <stdio.h>
int main() {
	int n;
	int number = -1;
	unsigned factorial = 1;
	do {
		printf("Enter a positive integer:");
		scanf("%d", &number);
	}while(number < 0);
	n = number;
	while(n >= 0) {
		if(n == 0){
			factorial *= 1;
		}
		else {
			factorial *= n;
		}
		--n;
	}
	printf("%d! is %u \n", number, factorial);
	return 0;
}

