#include <string.h>
#include <stdio.h>
char str[1010];
int main() {
    int i,j;
    while(scanf("%s", str) != EOF) {
        for(i=0; str[i] != '\0'; i++) {
            if(i % 2 == 0) {
                printf("%c", str[i]);
            }
        }
        printf(",");
        for(i=0; str[i] != '\0'; i++) {
            if(i % 2 == 1) {
                printf("%c", str[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
