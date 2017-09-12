/*
Cantor的数表
 */
#include <stdio.h>
int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		int k = 1, s = 0;
		for (;;) {
			s += k;
			if (s >= n) {// 所求项是第k条对角线的倒数第s-n+1个元素
				printf("%d/%d\n", s - n + 1, k - s + n);
				break;
			}
			k++;
		}
	}
	return 0;
}