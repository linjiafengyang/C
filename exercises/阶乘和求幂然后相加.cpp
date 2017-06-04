#include <stdio.h>
#include <math.h>
double fact(int n);
double mypow(float x, int n);
int main(){
	float x;
	int n;
	scanf("%f%d", &x, &n);
	double sum = 0;
	int i;
	for(i = 1; i <= n; i++) {
		if(i % 2 != 0) {
			sum += mypow(x, i) / fact(i);
		}
		else {
			sum -= mypow(x, i) / fact(i);
		}
	}
	printf("%.4lf", sum);
}
double fact(int n) {
	if(n <= 1) {
		return 1;
	}
	else {
		return n * fact(n - 1);
	}
}
double mypow(float x, int n) {
	return pow(x, n);
}
//x - x2/2! + x3/3! + ... + (-1)n-1xn/n!
