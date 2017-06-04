#include <stdio.h>
#define MAX(a, b, c) a > b && a > c ? a : b > c ? b : c
float findMax(int a, int b, int c);
int main() {
	float a, b, c;
	scanf("%f%f%f", &a, &b, &c);
	printf("%.3f\n", findMax(a, b, c));
	printf("%.3f", MAX(a, b, c));
	return 0;
}
float findMax(int a, int b, int c) {
	return a > b && a > c ? a : b > c ? b : c;
}
