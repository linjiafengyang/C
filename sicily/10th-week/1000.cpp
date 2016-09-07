#include <stdio.h>
int qualityPoints(int *n);
int main() {
    int i, a;
    int average[5];
    for(i = 0; i < 5; i++) {
        scanf("%d", &average[i]);
    }
    for(i = 0; i < 5; i++) {
        a = average[i];
        printf("%d ", qualityPoints(&a));   
    }
    return 0;
}
int qualityPoints(int *n) {
    if(*n > 90) {
        return 4;
    }
    else if(*n > 80) {
        return 3;
    }
    else if(*n > 70) {
        return 2;
    }
    else if(*n > 60) {
        return 1;
    }
    else {
        return 0;
    }
}
