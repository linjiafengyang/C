#include <stdio.h>
#include <stdlib.h>
double even(int n);
double odd(int n);
int main() {
	int n;
	double r;
	double (*pfunc)(int);
	printf("请输入一个数字：");
	scanf("%d", &n);
	if(n % 2 == 0) {
		pfunc = even;
	}
	else {
		pfunc = odd;
	}
	r = (*pfunc)(n);
	printf("%lf\n", r);
	system("pause");
	return 0;
}
double even(int n) {
	double s = 0;
	double a = 0;
	int i;
	for(i = 2; i <= n; i += 2) {
		a = (double)1 / i;
		s += a;
	}
	return s;
}
double odd(int n) {
	double s = 0;
	double a = 0;
	int i;
	for(i = 1; i <= n; i += 2) {
		a = (double)1 / i;
		s += a;
	}
	return s;
}
