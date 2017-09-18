/*
用最少的操作次数把序列1,2,...,n中的所有数都变成0。
每次操作可从序列中选择一个或多个整数，同时减去一个相同的正整数。
 */
#include <iostream>
int f(int n) {
	return n == 1 ? 1 : f(n / 2) + 1;
}
int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		printf("%d\n", f(n));
	}
	return 0;
}