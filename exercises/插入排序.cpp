#include <stdio.h>
int main() {
	int i, j;
	int temp;
	int a[10];
	for(i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	for(i = 1; i < 10; i++) {
		temp = a[i];
		for(j = i; j > 0 && a[j - 1] > temp; j--) {
			a[j] = a[j - 1];
		}
		a[j] = temp;
	}
	for(i = 0; i < 10; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}
