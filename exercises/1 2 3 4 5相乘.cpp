#include <stdio.h>
int main()
{
	int i=3,t=1;
	while(i<=11)
	{
		t=t*i;
		i=i+2;
	}
	printf("%d\n",t);
	return 0;
}
