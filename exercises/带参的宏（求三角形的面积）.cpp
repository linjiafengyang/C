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
//���������=SQRT(S*(S-a)*(S-b)*(S-c))
// ����S=(a+b+c)/2��a��b��cΪ�����ε����ߡ�
// �����������εĺ꣬һ��������area�� ��һ����������S��
// д�����ڳ������ô�ʵ�εĺ����������area��

