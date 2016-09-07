#include <stdio.h>
int main() {
    int n;
    int a[10][10], b[10][10], c[10][10];
    int i, j;
    scanf("%d", &n);
    while(n != 0){
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
                c[i][j] = a[i][j] + b[i][j];
                if(j != (n - 1)) {
                    printf("%d ", c[i][j]); 
                }
                else {
                    printf("%d\n", c[i][j]);
                }   
            }
        }
        scanf("%d", &n);    
    }   
}
