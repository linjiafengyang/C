#include <stdio.h>
#include <math.h>
unsigned seconds(unsigned h, unsigned m, unsigned s);
int main() {
	int hours;
	int minutes;
	int secs;
	int first;
	int second;
	int difference;
	printf("Enter the first time as three integers:");
	scanf("%d%d%d", &hours, &minutes, &secs);
	first = seconds(hours, minutes, secs);
	printf("Enter the second time as three integers:");
	scanf("%d%d%d", &hours, &minutes, &secs);
	second = seconds(hours, minutes, secs);
	difference = fabs(first - second);
	printf("%d", difference);
	return 0;
}
unsigned seconds(unsigned h, unsigned m, unsigned s) {
	return 3600 * h + 60 * m + s;
}

