#include <stdio.h>
int main() {
	int t, n, current;
	int a[10001];
	int i, j, temp;
	scanf("%d", &t);
	for(current = 0; current < t; current++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for(i = 0; i < n - 1; i++) {
			for(j = 0; j < n - i - 1; j++) {
				if(a[j] > a[j + 1]) {
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
		printf("%d\n", a[n - 2]);
	}
	return 0;
}
