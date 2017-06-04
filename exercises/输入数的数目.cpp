#include<stdio.h>
int main()
{
	int n, e;
	scanf ("%d", &n);
	while (n != 0)
	{
		scanf("%d", &e);
		printf ("%d\n", e);
		n = n - 1;
	}
}
