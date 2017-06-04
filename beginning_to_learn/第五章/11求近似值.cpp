#include <stdio.h>
#include <math.h>
double roundToInteger(double n);
double roundToTenths(double n);
double roundToHundredths(double n);
double roundToThousandths(double n);
int main() {
	int i;
	int count;
	double number;
	scanf("%d", &count);
	for(i = 0; i< count; i++) {
		printf("Enter a number:");
		scanf("%lf", &number);
		printf("%f\n", roundToInteger(number));
		printf("%f\n", roundToTenths(number));
		printf("%f\n", roundToHundredths(number));
		printf("%f\n", roundToThousandths(number));
	}
	return 0;
}
double roundToInteger(double n) {
	return floor(n + .5);
}
double roundToTenths(double n) {
	return floor(n * 10 + .5) / 10;
}
double roundToHundredths(double n) {
	return floor(n * 100 + .5) / 100;
}
double roundToThousandths(double n) {
	return floor(n * 1000 + .5) / 1000;
}
/*ÊäÈë 1 
	8.54739
Êä³ö 9.000000
	 8.500000
	 8.550000
	 8.547000 */ 
