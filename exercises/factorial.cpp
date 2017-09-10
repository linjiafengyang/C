/*
精确计算大数阶乘：利用数组存储运算结果
 */
#include <stdio.h>
#include <string.h>
const int max = 3000;
int f[max];
int main() {
	int n;
	scanf("%d", &n);
	memset(f, 0, sizeof(f));
	f[0] = 1;
	int i, j;
	for (i = 2; i <= n; i++) {
		int c = 0;
		for (j = 0; j < max; j++) {
			int s = f[j] * i + c;
			f[j] = s % 10;
			c = s / 10;
		}
	}
	for (j = max - 1; j >= 0; j--) if (f[j]) break; // 忽略前导0
	for (i = j; i >= 0; i--) printf("%d", f[i]);
	printf("\n");
	return 0;
}