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
		printf("优秀\n");
		break;
	case 6:
	case 7:
	case 8:
		if (mark < 85)
		{
			printf("良好\n");
		}
		else
		{
			printf("优秀\n");
		}
		break;
	
	default:
		printf("不及格\n");
		break;
	}
}