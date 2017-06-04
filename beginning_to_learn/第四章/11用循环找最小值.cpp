#include <stdio.h>
int main() {
	int number;
	int value;
	int smallest;
	int i;
	printf("Enter the number of intergers to be processed:");
	scanf("%d", &number);
	printf("Enter an integer:");
	scanf("%d", &smallest);
	for(i = 2; i <= number; i++) {
		printf("Enter next integer:");
		scanf("%d", &value);
		if(value < smallest) {
			smallest = value;
		}
	}
	printf("\nThe smallest integer is: %d\n", smallest);
	return 0;
}
