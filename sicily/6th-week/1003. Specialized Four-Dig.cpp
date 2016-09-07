#include <stdio.h>
int main() {
	int i, j;
	int a[4] = {0};
	int temp, m, n, k, p;
	for(i = 1000; i <= 9999; i++) {
		m = 0;
		n = 0;
		k = 0;
		p = 0;
		temp = i;
		for(j = 0; j <= 3; j++) {
			a[j] = temp % 12;
			temp = temp / 12;
			n = n + a[j];
		}
		temp = i;
		for(j = 0; j <= 3; j++) {
			a[j] = temp % 16;
			temp = temp / 16;
			k = k + a[j];
		}
		temp = i;
		for(j = 0; j <= 3; j++) {
			a[j] = temp % 10;
			temp = temp / 10;
			p = p + a[j];
		}
		if(p == n && n == k) {
			printf("%d\n", i);
		}
	}
	return 0;
}
