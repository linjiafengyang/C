#include <stdio.h>
int main() {
    int testnum, n, i, j, k, flag;
    int a[101];
    scanf("%d", &testnum);
    for(i = 0; i < testnum; i++) {
        scanf("%d", &n);
        for(j = 0; j < n; j++) {
            scanf("%d", &a[j]);
            if(j == 0) {
                printf("%d", a[0]);
            }
            else {
                k = 0;
                flag = 0;
                for(k = 0; k < j; k++) {
                    if(a[j] != a[k]) {
                        flag = flag + 1;
                    }
                }
                if(flag == j) {
                    printf(" %d", a[j]);
                }
            }
        }
        printf("\n");
    }    
    return 0;
}
