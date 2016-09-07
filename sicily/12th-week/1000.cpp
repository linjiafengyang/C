#include <stdio.h>
int main() {
    int n;
    int j = 1;
    scanf("%d", &n);
    while(n) {
        int i;
        int a[10001] = {0};
        int temp = 0;
        for(i = 0; i < n; i++) {
            scanf("%d", &temp);
            a[temp]++;
        }
        printf("Case %d:\n", j++);
        for(i = 0; i < 10001; i++) {
            if(a[i] != 0) {
                printf("%d %d\n", i, a[i]);
            }
        }
        scanf("%d", &n);
    }
}
