#include <stdio.h>
int main() {
	int n, i, j, k, temp;
	int a[10010];
	int b[20];
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &b[i]);
		for(j = 0; j < b[i]; j++) {
			scanf("%d", &a[j]);
		}
		for(j = 1; j < b[i]; j++) {
			for(k = 0; k < (b[i] - 1); k++) {
				if(a[k] > a[k+1]) {
					temp = a[k];
					a[k] = a[k+1];
					a[k+1] = temp;
				}
			}
		}
		for(j = 0; j < b[i]; j++) {
			printf("%d ", a[j]);
		}
		printf("\n");
	}
	return 0;
}
