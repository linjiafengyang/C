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
	int b[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//�����·ݵ����� 
	struct sdate datenum;
	scanf("%d%d%d", &datenum.year, &datenum.mon, &datenum.date);
	if(datenum.year % 4 == 0 && datenum.year % 100 != 0 || datenum.year % 400 == 0) {
		flag = 1;//�ж����� 
	}
	for(i = 0; i < datenum.mon - 1; i++) {
		count = count + b[i];//�������֮ǰ������ 
	}
	if(datenum.mon > 2) {
		if(flag) {
			count = count + datenum.date + 1;//�����һ 
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
