#include <stdio.h>
long factorial(long number);
void printRecursion(int n);
int main() {
	int i;
	for(i = 0; i <= 10; i++) {
		printf("%2d! = %ld\n", i, factorial(i));
	}
	return 0;
}
long factorial(long number) {
	if(number <= 1) {
		return 1;
	}
	else {
		printRecursion(number);
		return (number * factorial(number - 1));
	}
}
void printRecursion(int n) {
	printf("number = %*d\n", n, n);//%*d 中的 * 表示域宽，后面两个 n ：第一个 n 表示域宽 
}
