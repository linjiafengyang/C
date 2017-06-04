#include <stdio.h>
#include <math.h>
int main() {
	float a, x1, x2;
	scanf("%f", &a);
	x1 = 1;
	x2 = a;
	while(fabs(x1 - x2) >= 1e-5) {
		x1 = x2;
		x2 = (x1 + a / x1) / 2;
	}
	if(x1 == x2) {
		printf("%.3f", x1);
	}
	else {
		printf("%.3f %.3f", x1, x2);
	}
	return 0;
}
