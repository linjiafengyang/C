#include <stdio.h>
int main() {
	int year;
	int leapyear;
	int days;
	int month;
	int space;
	int dayposition;
	int daynum;
	do {
		printf("Enter a calendar year between 1994 and 1999:");
		scanf("%d", &year);
	} while(year < 1994 || year > 1999);
	switch(year) {
		case 1994:
			dayposition = 7;
			break;
		case 1995:
			dayposition = 1;
			break;
		case 1996:
			dayposition = 2;
			break;
		case 1997:
			dayposition = 4;
			break;
		case 1998:
			dayposition = 5;
			break;
		case 1999: 
			dayposition = 6;
			break;
	}
	if(year % 400 == 0) {
		leapyear = 1;
	}
	else if(year % 4 == 0 && year % 100 != 0) {
		leapyear = 1;
	}
	else {
		leapyear = 0;
	}
	for(month = 1; month <= 12; month++) {
		switch(month) {
			case 1:
				printf("\n\nJanuary %d\n", year);
				days = 31;
				break;
			case 2:
				printf("\n\nFebruary %d\n", year);
				days = leapyear == 1 ? 29 : 28;
				break;
			case 3:
				printf("\n\nMarch %d\n", year);
				days = 31;
				break;
			case 4:
				printf("\n\nApril %d\n", year);
				days = 30;
				break;
			case 5:
				printf("\n\nMay %d\n", year);
				days = 31;
				break;
			case 6:
				printf("\n\nJune %d\n", year);
				days = 30;
				break;
			case 7:
				printf("\n\nJuly %d\n", year);
				days = 31;
				break;
			case 8:
				printf("\n\nAugust %d\n", year);
				days = 31;
				break;
			case 9:
				printf("\n\nSeptember %d\n", year);
				days = 30;
				break;
			case 10:
				printf("\n\nOctober %d\n", year);
				days = 31;
				break;
			case 11:
				printf("\n\nNovember %d\n", year);
				days = 30;
				break;
			case 12:
				printf("\n\nDeceber %d\n", year);
		}
		printf(" S  M  T  W  R  F  S\n");
		for(space = 1; space < dayposition; space++) {
			printf("   ");
		}
		for(daynum = 1; daynum <= days; daynum++) {
			printf("%2d ", daynum);
			if(dayposition % 7 == 0) {
				printf("\n");
				dayposition = 1;
			}
			else {
				++dayposition;
			}
		}
	}
	return 0;
}
