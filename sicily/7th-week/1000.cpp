#include <stdio.h>
#define L 50 
int main() {
    int i, j, k, n;
    int mat[L][L];
    int value = 1;
    scanf("%d", &n);
    for(k = 0; k < (n + 1) / 2; k++) {
        for(i = k; i < n - k; i++) {
            mat[k][i] = value++;
        }
        for(i = k + 1; i < n - k; i++) {
            mat[i][n - k - 1] = value++;
        }
        for(i = n - k - 2; i >= k; i--) {
            mat[n - k - 1][i] = value++;
        }
        for(i = n - k - 2; i > k; i--) {
            mat[i][k] = value++;
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j < n - 1; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("%d", mat[i][j]);
        printf("\n");
    }
}
