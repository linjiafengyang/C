#include <stdio.h>
int main() {
    int n, i;
    while(scanf("%d", &n) != EOF) {
        int a[16];
        if(n >= 0) {
            for(i = 0; i <= 15; i++) {
                a[i] = n % 2;
                n = n / 2;
            }
        }
        if(n < 0) {
            for(i = 0; i <= 15; i++) {
                a[i] = 1;
            }
            n = 65536 + n;
            i = 0;
            while(n) {
                a[i] = n % 2;
                n = n / 2;
                i++;
            }
        }
        for(i = 15; i >= 0; i--) {
            printf("%d", a[i]);
        }
        printf("\n");
    }
}
