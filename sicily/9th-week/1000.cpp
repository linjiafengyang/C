#include <stdio.h>
int add2(int a);
int minus1(int a);
int main() {
    int a, b;
    scanf("%d", &a);
    b = add2(a);
    printf("%d", minus1(b));
}
int add2(int n) {
    n += 2;
    return n;
}
int minus1(int n) {
    n -= 1;
    return n;
}
