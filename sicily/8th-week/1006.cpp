#include <stdio.h>
int a[100001], c[100001];
main () {
    int i, n, b, j, d;
    for (i = 0; i < 100001; i++) {
        a[i] = 0;
    }
    a[0] = 1;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        b = 0;
        for (j = 0; j < 100000; j++) {
            c[j] = a[j];
            a[j] = (a[j] * 3) % 10 + b;
            if (a[j] >= 10) {
                a[j] = a[j] - 10;
                b = (c[j] * 3) / 10 + 1;
            }
            else {
                b = (c[j] * 3) / 10;
            }
        }  
    }
    for (i = 99999; i >= 0; i--) {
        if(a[i] != 0) {
            d = i;
            break;
        }
    }
    for (i = d; i >= 0;i--) {
        printf("%d", a[i]);
    }
    printf("\n");
}
