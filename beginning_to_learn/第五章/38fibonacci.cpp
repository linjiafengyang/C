#include <stdio.h>
#define MAX 23
int fibonacci(int n);
int main() {
	int loop;
	for(loop = 0; loop <= MAX; loop++) {
		printf("fibonacci(%d) = %d\n", loop, fibonacci(loop));
	}
	return 0;
}
int fibonacci(int n) {
	int j;
	int fib[MAX];
	fib[0] = 0;
	fib[1] = 1;
	for(j = 2; j <= n; j++) {
		fib[j] = fib[j - 1] + fib[j - 2];
	}
	return fib[n];
}
