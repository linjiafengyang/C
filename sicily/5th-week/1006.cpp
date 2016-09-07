#include <stdio.h>
int main() {
    unsigned int N;
    int i;
    int num;
    int max;
    max = 0;
    scanf("%d", &N);
    for(i = 1; i <= N; i++) {
        scanf("%d", &num);
        if(num > max){
            max = num;
        }
    }
    printf("%d\n", max);
    return 0;
}
