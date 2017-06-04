#include <stdio.h>
#define LEAP_YEAR(year) (year) % 4 == 0 && (year) % 100 != 0 || (year) % 400 == 0
int main() {
	int year;
	scanf("%d", &year);
	if(LEAP_YEAR(year)) {
		printf("L");
	}
	else {
		printf("N");
	}
	return 0;
}
