#include <stdio.h>
int main(){
    int x;
    int a;
    int b;
    int c;
    int d;
    scanf("%d", &x);
    a = x % 10;
    b = x / 100;
    c = x % 100;
    d = (c - a)/ 10;
    printf("%d\n", a + b + d);
    return 0;
}
//932 14 
