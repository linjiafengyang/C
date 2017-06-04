#include <stdio.h>
#include <math.h>
#define AREA(a, b, c, s)area = sqrt(s * (s - a) * (s - b) * (s - c));
#define S(a, b, c)s = (a + b + c) / 2;
main()
{
    float a, b, c, s;
    float area;
    scanf("%f%f%f", &a, &b, &c);
    S(a, b, c);
    AREA(a, b, c, s);
    printf("%.3f", area);
}
//三角形面积=SQRT(S*(S-a)*(S-b)*(S-c))
// 其中S=(a+b+c)/2，a、b、c为三角形的三边。
// 定义两个带参的宏，一个用来求area， 另一个宏用来求S。
// 写程序，在程序中用带实参的宏名来求面积area。

