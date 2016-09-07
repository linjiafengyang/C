#include <stdio.h>
int main() {
    int a[10], total = 0;
    float average;
    int i;
    for(i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
        total = total + a[i];
    }
    average = (float)total / 10;
    for(i = 0; i < 10; i++) {
        if(a[i] < average) {
            printf("%d\n", a[i]);
        } 
    }
    return 0;
}                                 
