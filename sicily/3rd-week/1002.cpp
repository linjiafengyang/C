#include <stdio.h>
int main() {
    char a, b;
    scanf("%c", &a);
    b = a - ('A' - 'a');
    printf("%c\n", b);
    return 0;
}
