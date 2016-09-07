#include <stdio.h>
#include <math.h>
int main() {
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    float d, x1, x2;
    d = pow(b, 2) - 4 * a * c;
    if(d >= 0)
    {
        d = sqrt(d);
        x1 = (-b + d) / (2 * a);
        x2 = (-b - d) / (2 * a);
        if(x1 > x2){
            printf("%.3f %.3f\n", x2, x1);
        }
        else
            printf("%.3f %.3f\n", x1, x2);
    }
    else
        printf("There is no solution!\n");
    return 0;
}
