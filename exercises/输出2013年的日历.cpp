#include <stdio.h>
int FirstDay(int, int); 
int LenOfMonth(int);
int main() {
	int i, flagInput = 0; 
	int month; 
	int day, weekday, daysOfMonth;
	for(month = 1; month <= 12; month++) {
		weekday = FirstDay(2013, month); 
		printf("\n\n��ݣ�2013\t");
		printf("�·ݣ�%6d\n\n", month);
		printf("---------------------------------------\n");
		printf("SUN   MON   TUE   WED   THU   FRI   SAT\n");
		printf("---------------------------------------\n");
		for(i = 0; i < weekday; i++) {  //����ÿ�µ�һ�������ڼ������������ÿ��ǰ��Ŀո�
			printf("%-6c",' ');
		} 
		daysOfMonth = LenOfMonth(month);   //�����ÿ�µ�����
		for(day = 1; day <= daysOfMonth; day++) {  //����ÿ�µ��������������
			printf("%-6d", day);
			weekday = (weekday + 1) % 7;    //�������ǰ�����ڼ��������ж��Ƿ�س�
			if(weekday == 0) {   //���������ĩ������
				printf("\n");
			} 
		}
		printf("\n");
		printf("---------------------------------------\n");
	}
	return 0;
}
int LenOfMonth(int month) {
	int dayNumber;    //��������//�����С�£��� 30 ��
	if(month == 4 || month ==6 || month==9 || month== 11) {   
		dayNumber = 30;
	}
	else if(month == 2) { 
		dayNumber = 28;		//2013����28��
	}				//�������£��� 31 ��
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

