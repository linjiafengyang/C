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
    case 0: printf("������\n"); break;
    case 1: printf("����һ\n"); break;
    case 2: printf("���ڶ�\n"); break;
    case 3: printf("������\n"); break;
    case 4: printf("������\n"); break;
    case 5: printf("������\n"); break;
    case 6: printf("������\n"); break;
    }
 
	return 0;
}