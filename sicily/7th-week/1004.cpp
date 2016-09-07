#include <stdio.h>
int main() {
    int n, temp;
    int a[10][10], b[10][10], c[10][10];
    int i, j, k;
    while(scanf("%d", &n) != EOF){
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                scanf("%d", &b[i][j]);
            }
        }
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                temp = 0;
                for(k = 0; k < n; k++) {
                    temp += a[i][k] * b[k][j];
                }
                c[i][j] = temp;
                if(j != (n - 1)) {
                    printf("%d ", c[i][j]); 
                }
                else {
                    printf("%d\n", c[i][j]);
                }
            }
        }   
    }   
}
