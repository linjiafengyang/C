#include <stdio.h>
int fibonacci(int n);
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
int fibonacci(int n) {
    int i;
    int a = 1, b = 1, c = 1;
    for(i = 2; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
