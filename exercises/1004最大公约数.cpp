#include <stdio.h>
long gcd(long a, long b);
int gcd(int a, int b);
int main() {
	long m, n;
	while(scanf("%ld%ld", &m, &n) != EOF) {
		printf("%ld\n%d", gcd(m, n), gcd(m, n));
	}
}
long gcd(long a, long b) {
	return (b > 0) ? gcd(b, a % b) : a;
}
int gcd(int a, int b) {
	while(b > 0) {
		int r;
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
