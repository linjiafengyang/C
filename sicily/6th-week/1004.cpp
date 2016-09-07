#include <stdio.h>
int main()
{
    int n, i;
    scanf("%d", &n);
    for(i = 7; i >= 0; i--)
    {       
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
    return 0;
}
