#include <stdio.h>
int main() {
    int T;
    int i;
    int year;
    scanf("%d", &T);
    for(i = 1; i <= T; i++){
        scanf("%d", &year);
        if((year % 4 == 0 && year % 100 != 0)||(year % 400 ==0)) {
            printf("%d leap year\n", year);
        }
        else {
            printf("%d common year\n", year);
        }
    }
    return 0;
}
