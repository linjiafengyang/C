#include <stdio.h>
int main() {
	int n;
	int i, k;
	int d[10];
	int result1 = 0;
	int result2 = 0;
	scanf("%d", &n);//八进制转化为十进制 
	for(i = 1; n != 0; i *= 8) {
		result1 = result1 + (n % 10) * i;
		n = n / 10;
	}
	printf("%d\n", result1);
	scanf("%d", &n);//二进制转化为十进制 
	for(i = 1; n != 0; i *= 2) {
		result2 = result2 + (n % 10) * i;
		n = n / 10;
	}
	printf("%d\n", result2);
	scanf("%d", &n);//十进制转化为二进制 
	for(i = 0; n != 0; i++) {
		d[i] = n % 2;
		n = n / 2;
	}
	for(k = i - 1; k >= 0; k--) {
		printf("%d", d[k]);
	}
	printf("\n");
	scanf("%d", &n);//十进制转化为八进制 
	for(i = 0; n != 0; i++) {
		d[i] = n % 8;
		n = n / 8;
	}
	for(k = i - 1; k >= 0; k--) {
		printf("%d", d[k]);
	}
}
