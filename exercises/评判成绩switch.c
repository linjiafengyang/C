#include <stdio.h>
int main()
{
	int mark;
	scanf("%d", &mark);
        if(mark>100||mark<0)
          {
            printf("input error!"); 
            return 0; 
          }
	switch (mark / 10)
	{
	case 9:
	case 10:
		printf("����\n");
		break;
	case 6:
	case 7:
	case 8:
		if (mark < 85)
		{
			printf("����\n");
		}
		else
		{
			printf("����\n");
		}
		break;
	
	default:
		printf("������\n");
		break;
	}
}