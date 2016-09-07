#include <stdio.h>
int main() {
	int t, current, k;
	scanf("%d", &t);
	int n, i, j, temp;
	int a[101], b[101];
	for(current = 0; current < t; current++) {
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for(i = 0; i <= 100; i++) {
			b[i] = 1;
		}
		for(j = n - 1; j > 0; j--) {
			for(i = j - 1; i >= 0; i--) {
				if(a[j] == a[i]) {
					a[j] = 10;
					b[a[i]] = b[a[i]] + 1;
					break;
				}
			}
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
		for(i = 0; i < n; i++) {
			if(a[i] != 10) {
				printf("%d ", a[i]);
				printf("%d\n", b[a[i]]);
			}
		}
	}
	return 0;
}
/*
2
3
1 7 1
7
5 6 5 6 6 5 5
*/
/*
1 2
7 1
5 4
6 3
*/
