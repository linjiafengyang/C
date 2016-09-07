#include <stdio.h>
int main() {
    float a[3][3];
    int i, j;
    float max;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            scanf("%f", &a[i][j]);
        }
    }
    max = a[0][0];
    for(i = 1, j = 1; i < 3, j < 3; i++, j++) {
        if(a[i][j] > max) {
            max = a[i][j];
        }
    }
    printf("%.1f ", max);
    max = a[0][2];
    for(i = 1, j = 1; i < 3, j >= 0; i++, j--) {
        if(a[i][j] > max) {
            max = a[i][j];
        }
    }
    printf("%.1f ", max);
    return 0;
}
