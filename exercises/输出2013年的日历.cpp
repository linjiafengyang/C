#include <stdio.h>
int FirstDay(int, int); 
int LenOfMonth(int);
int main() {
	int i, flagInput = 0; 
	int month; 
	int day, weekday, daysOfMonth;
	for(month = 1; month <= 12; month++) {
		weekday = FirstDay(2013, month); 
		printf("\n\n年份：2013\t");
		printf("月份：%6d\n\n", month);
		printf("---------------------------------------\n");
		printf("SUN   MON   TUE   WED   THU   FRI   SAT\n");
		printf("---------------------------------------\n");
		for(i = 0; i < weekday; i++) {  //根据每月第一天是星期几，来决定输出每月前面的空格
			printf("%-6c",' ');
		} 
		daysOfMonth = LenOfMonth(month);   //计算出每月的天数
		for(day = 1; day <= daysOfMonth; day++) {  //根据每月的天数，输出日子
			printf("%-6d", day);
			weekday = (weekday + 1) % 7;    //计算出当前是星期几，决定判断是否回车
			if(weekday == 0) {   //如果到了周末，则换行
				printf("\n");
			} 
		}
		printf("\n");
		printf("---------------------------------------\n");
	}
	return 0;
}
int LenOfMonth(int month) {
	int dayNumber;    //计算天数//如果是小月，则 30 天
	if(month == 4 || month ==6 || month==9 || month== 11) {   
		dayNumber = 30;
	}
	else if(month == 2) { 
		dayNumber = 28;		//2013年是28天
	}				//其他大月，则 31 天
	else { 
		dayNumber = 31;
	}
	return dayNumber;
}
int FirstDay(int year, int month) {
	int n = year - 1900;
	int i;
	int dayTotal[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
	n = n + (n - 1) / 4 + 1; 
	n = n % 7;
	for(i = 0; i < month - 1; i++) {   
		n += dayTotal[i];
	}
	if(month != 1) { 
		n %= 7;
	} 
	return n; 
}

