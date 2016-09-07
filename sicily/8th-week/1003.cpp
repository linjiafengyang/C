#include <stdio.h> 
#include <math.h>
main () {
    int n, b[100];
    int i, j, h;
    char a[101][100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        if (b[i] == 1) {
            scanf("%s", &a[i]);
        }
        else {
            scanf("%s", &a[i]);
            printf("%s ", a[i]);
            for (j = i - 1; j >= 0; j--) {
                if (b[j] == 1) {
                    printf("%s\n", a[j]);
                    b[j] = 0;
                    break;
                }
            }
        }
    }
}
