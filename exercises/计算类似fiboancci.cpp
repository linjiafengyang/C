#include <stdio.h>
int main() {
	int i;
	int n;
	float a, b, c, total;
	a = 1.0;
	b = 1.0;
	total = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		c = a + b;
		total += c / a;
		b = a;
		a = c;
	}
	printf("%.2f", total);
	return 0;
}
//¼ÆËã 2/1 + 3/2 + 5/3 + 8/5.¡£¡£ 
