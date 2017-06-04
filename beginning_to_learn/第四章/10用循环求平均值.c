#include <stdio.h>
int main() {
	int value;
	int count = 0;
	int total = 0;
	printf("Enter an integer (9999 to end):");
	scanf("%d", &value);
	while(value != 9999) {
		total += value;
		++count;
		printf("Enter next integer (9999 to end):");
		scanf("%d", &value);
	}
	if(count != 0) {
		printf("\nThe average is: %.2f\n", (double)total / count);
	}
	else {
		printf("\nNo values were entered.\n");
	}
	return 0;
}
