#include <stdio.h>
int main() {
	char s[110];
	scanf("%s", s);
	int i;
	int sum = 0;
	for(i = 0; s[i] != '\0'; i++) {//读出每一个数字 
		sum = sum + s[i] - '0';//计算和 
	}
	int mask = 1;
	int temp = sum;
	while(temp > 9) {
		temp /= 10;
		mask *= 10;//计算sum的位数，千位还是？ 
	}
	while(mask > 0) {
		int d = sum / mask;//每一位上的数字 
		switch(d) {
			case 0:
				printf("ling");
				break;
			case 1:
				printf("yi");
				break;
			case 2:
				printf("er");
				break;
			case 3:
				printf("san");
				break;
			case 4:
				printf("si");
				break;
			case 5:
				printf("wu");
				break;
			case 6:
				printf("liu");
				break;
			case 7:
				printf("qi");
				break;
			case 8:
				printf("ba");
				break;
			case 9:
				printf("jiu");
				break;
		}
		if(mask > 9) {//保证最后一个拼音后面没有空格 
			printf(" ");
		}
		sum %= mask;//得到余数 
		mask /= 10;//位数减一 
	}
}
