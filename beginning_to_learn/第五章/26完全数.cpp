#include <stdio.h>
int perfect(int value);
int main() {
	int j;
	printf("For the integers from 1 to 1000:\n");
	for(j = 2; j <= 1000; j++) {
		if(perfect(j)) {
			printf("%d is perfect\n", j);
		}
	}
	return 0;
}
int perfect(int value) {
	int factorSum = 1;
	int i;
	for(i = 2; i <= value / 2; i++) {
		if(value % i == 0) {
			factorSum += i;
		}
	}
	if(factorSum == value) {
		return 1;
	}
	else {
		return 0;
	}
}
