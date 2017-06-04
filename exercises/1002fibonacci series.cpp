#include <stdio.h>
long fibonacci(long n);
int main() {
	int t, i, n, m;
	scanf("%d", &t);
	for(i = 0; i < t; i++) {
		scanf("%d", &m);
		for(n = 0; fibonacci(n) < m; n++);
		if(fibonacci(n) == m) {
			printf("%d\n", n + 1);
		}
		else {
			printf("0\n");
		}
	}
}
long fibonacci(long n) {
	if(n == 0 || n == 1) {
		return n;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}//ÔÚsicily»á³¬Ê± 
