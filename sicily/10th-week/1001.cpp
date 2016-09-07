#include <stdio.h>
int main() {
    int t, i, j, n;
    float num[100];
    float temp;
    int count;
    scanf("%d", &t);
    for(i = 1; i <= t; i++) {
        scanf("%d", &n);
        temp = 0.0;
        count = 0;
        for(j = 0; j < n; j++) {
            scanf("%f", &num[j]);
            temp = temp + num[j];
        }
        temp = temp / n;
        for(j = 0; j < n; j++) {
            if(temp < num[j]) {
                count++;
            }
        }
        printf("%d\n", count);
    }
}
