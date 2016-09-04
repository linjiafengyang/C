#include <stdio.h>
int factorial(int a, int b);
int main() {
	int sum = 0, i;
	sum += 4;
	for(i = 2; i < 8; i++) {
		sum += 4 * (factorial(7, i - 1) - factorial(6, i - 2));
	}
	printf("可以组成%d个奇数\n", sum);
	return 0;
}
int factorial(int a, int b) {
	int i, sum = 1;
	if(b <= 0) {
		return 1;
	}
	for(i = 0; i < b; i++) {
		sum *= (a - i);
	}
	return sum;
}
