#include <stdio.h>
#include <math.h>
int main() {
    int t, i;
    double a, b, c;
    scanf("%d", &t);
    for(i = 1; i <= t; i++) {
        scanf("%lf%lf%lf", &a, &b, &c);
        if((a >= -100 && a <= 100) && (b >= -100 && b <= 100) && (c >= -100 && c <= 100)) {
            if(fabs(a + b - c) < 1e-10) {
                printf("Yes\n");
            }
            else {
                printf("No\n");
            }
        }   
    }
    return 0;
}
