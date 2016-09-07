#include <stdio.h>
int main() {
    int N;
    int count;
    int num;
    int max;
    int min;
    scanf("%d", &N);
    max = 0;
    min = 32767;
    count = 1;
    while(count <= N) {
        scanf("%d", &num);
        if(num > max){
            max = num;
        }
        if(num < min){
            min = num;
        }
        count++;
    }
    printf("%d %d\n", max, min);
    return 0;
}
