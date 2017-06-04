#include <stdio.h>
#include <math.h>
void f1(int a, int b, int c);
void f2(int a, int b, int c);
void f3(int a, int b, int c);
float x1, x2;
int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if(b * b - 4 * a * c > 0) {
		f1(a, b, c);
	}
	if(b * b - 4 * a * c == 0) {
		f2(a, b, c);
	}
	if(b * b - 4 * a * c < 0) {
		f3(a, b, c);
	}
	return 0;
}
void f1(int a, int b, int c) {
	x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	printf("x1=%.3f x2=%.3f", x1, x2);
}
void f2(int a, int b, int c) {
	x1 = -b / (2 * a);
	x2 = -b / (2 * a);
	printf("x1=%.3f x2=%.3f", x1, x2);
}
void f3(int a, int b, int c) {
	float x, y;
	x = (float)-b / (2 * a);
	y = (float)sqrt(-(b * b - 4 * a * c)) / (2 * a);
	printf("x1=%.3f+%.3fi x2=%.3f-%.3fi", x, y, x, y);
}
