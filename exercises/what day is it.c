#include <stdio.h>
int main(){                                                          //��ķ����ɭ���㹫ʽW=(d+1+2*m+3*(m+1)/5+Y+Y/4-Y/100+Y/400)%7.                                                                   
	int Y,W;                                                         // d��ʾ���ڵ�������m��ʾ�·ݣ�Y��ʾ���
	scanf("%d",&Y);                                                  //�������WΪ0 1 2 3 4 5 6���ֱ��ʾ�����쵽������ 
	W=(1+1+2*13+3*(13+1)/5+(Y-1)+(Y-1)/4-(Y-1)/100+(Y-1)/400)%7;     
	switch(W){
		case 0:
		printf("0\n");
		break;
		case 1:
		printf("1\n");
		break;
		case 2:
		printf("2\n");
		break;
		case 3:
		printf("3\n");
		break;
		case 4:
		printf("4\n");
		break;
		case 5:
		printf("5\n");
		break;
		case 6:
		printf("6\n");
		break;
	}
	return 0;
}
