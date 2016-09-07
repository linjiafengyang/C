#include <stdio.h>
int main() {
    int i, j, flag;
    int a[20];
    for(i = 0; i < 20; i++) {
        scanf("%d", &a[i]);
        if(a[i] >= 10 && a[i] <= 100){
            if(i == 0) {
                printf("%d ", a[0]);
            }
            else {
                flag = 0;
                for(j = 0; j < i; j++) {
                    if(a[j] != a[i]) {
                        flag = flag + 1;
                    }
                }
                if(flag == i) {
                    printf("%d ",a[i]);
                }
            }
        }
    }
    return 0;
}
