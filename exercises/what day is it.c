#include <stdio.h>
int main(){                                                          //基姆拉尔森计算公式W=(d+1+2*m+3*(m+1)/5+Y+Y/4-Y/100+Y/400)%7.                                                                   
	int Y,W;                                                         // d表示日期的天数，m表示月份，Y表示年份
	scanf("%d",&Y);                                                  //算出来的W为0 1 2 3 4 5 6；分别表示星期天到星期六 
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
