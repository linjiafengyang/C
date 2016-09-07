#include "stdio.h"
main () {
    int n, m, i, j;
    while (scanf("%d%d", &n, &m) != EOF) {
        char a[n + 1][m + 1];
        for (i = 0; i < n; i++) {
            scanf("%s", &a[i]);
        }
        for (i = 0; i < n; i++) {
            for (j = m - 1; j >= 0; j--) {
                if (a[i][j] == 'b' ) {
                    printf ("d") ;
                }
                else {
                    printf("%c", a[i][j]); 
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}
