#include <stdio.h>
struct sdate {
	int year;
	int mon;
	int date;
};
int main() {
	int i;
	int flag = 0;
	int count = 0;
	int b[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//各个月份的天数 
	struct sdate datenum;
	scanf("%d%d%d", &datenum.year, &datenum.mon, &datenum.date);
	if(datenum.year % 4 == 0 && datenum.year % 100 != 0 || datenum.year % 400 == 0) {
		flag = 1;//判断闰年 
	}
	for(i = 0; i < datenum.mon - 1; i++) {
		count = count + b[i];//计算该月之前的天数 
	}
	if(datenum.mon > 2) {
		if(flag) {
			count = count + datenum.date + 1;//闰年加一 
		}
		else {
			count = count + datenum.date;
		}
	}
	else {
		count = count + datenum.date;
	}
	printf("%d", count);
	return 0;
}
