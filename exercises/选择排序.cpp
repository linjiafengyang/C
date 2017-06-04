#include <stdio.h>
int main() {
	int a[10];
	int i, j, temp, hold;
	for(i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
	}
	for(i = 0; i < 9; i++) {
		temp = i;
		for(j = i + 1; j < 10; j++) {
			if(a[j] < a[temp]) {
				temp = j;
			}
		}
		if(temp != i) {
			hold = a[temp];
			a[temp] = a[i];
			a[i] = hold;
		}
	}
	for(i = 0; i < 10; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
