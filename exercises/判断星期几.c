#include <stdio.h>
int main(){
	int d,m,Y,W;
	scanf("%d%d%d",&Y,&m,&d);
	if(m==1||m==2){
		m+=12;
		Y--;
	}
	W=(d+1+2*m+3*(m+1)/5+Y+Y/4-Y/100+Y/400)%7;
	printf("%d\n",W);
	switch(W)
    {
    case 0: printf("星期天\n"); break;
    case 1: printf("星期一\n"); break;
    case 2: printf("星期二\n"); break;
    case 3: printf("星期三\n"); break;
    case 4: printf("星期四\n"); break;
    case 5: printf("星期五\n"); break;
    case 6: printf("星期六\n"); break;
    }
 
	return 0;
}