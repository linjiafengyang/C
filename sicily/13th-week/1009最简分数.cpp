#include <stdio.h>
int main() {
	int n;
	int i, j, k;
	int m = 0;
	int temp;
	float a[10000];
	int b[10000], c[10000];
	scanf("%d", &n);
	printf("0/1\n");
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= i; j++) {
			temp = 0;
			for(k = 1; k <= j; k++) {
				if(j % k == 0 && i % k == 0) {
					temp++;
				}
			}
			if(temp == 1) {
				a[m] = (float)j / i;
				b[m] = j;
				c[m] = i;
				m++;
			}
		}
	}
	for(i = 0; i < m - 1; i++) {
		for(j = 0; j < m - i - 1; j++) {
			if(a[j] > a[j + 1]) {
				float temp1 = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp1;
				int temp2 = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp2;
				temp2 = c[j];
				c[j] = c[j + 1];
				c[j + 1] = temp2;
			}
		}
	}
	for(i = 0; i < m; i++) {
		printf("%d/%d\n", b[i], c[i]);
	}
	return 0;
}
