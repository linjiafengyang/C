#include <stdio.h>
#include <math.h>
double calculaterCharges(double hours);
int main() {
	double h;
	double currentCharge;
	double totalCharges = 0.0;
	double totalHours = 0.0;
	int i;
	int first = 1;
	printf("Enter the hours parked for 3 cars:");
	for(i = 1; i <= 3; i++) {
		scanf("%lf", &h);
		totalHours += h;
		if(first) {
			printf("%5s%15s%15s\n", "Car", "Hours", "Charge");
			first = 0;
		}
		totalCharges += (currentCharge = calculaterCharges(h));
		printf("%5d%15.1f%15.2f\n", i, h, currentCharge);
	}
	printf("%5s%15.1f%15.2f\n", "Total", totalHours, totalCharges);
	return 0;
}
double calculaterCharges(double hours) {
	double charge;
	if(hours < 3.0) {
		charge = 2.0;
	}
	else if(hours < 19.0) {
		charge = 2.0 + .5 * ceil(hours - 3.0);//ceil(x)不小于x的整数 
	}
	else {
		charge = 10.0;
	}
	return charge;
}
/*输入 1.5 4.0 24.0*/ 
