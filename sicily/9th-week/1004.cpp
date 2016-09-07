#include <stdio.h>
long gcd(long a, long b);
int main() {
    long m, n;
    while(scanf("%ld%ld", &m, &n) != EOF) {
        printf("%ld\n", gcd(m, n));   
    }
}
long gcd(long a, long b) {
    return (b > 0) ? gcd(b, a % b) : a;
}
