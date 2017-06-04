#include <stdio.h>
int main() {
	int n;
	int *a;
	int i;
	printf("Input array length:");
	scanf("%d", &n);
	a = (int *)calloc(n, sizeof(int));
	for(i = 0; i < n; i++) {
		a[i] = i + 1;
		printf("%-5d", a[i]);
		if((i + 1) % 10 == 0) {
			printf("\n");
		}
	}
	free(a);
	a = NULL;
	printf("\n");
	return 0;
}
