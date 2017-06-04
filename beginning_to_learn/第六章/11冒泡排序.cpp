#include <stdio.h>
#define SIZE 10
int main() {
	int a[SIZE] = {9, 5, 7, 6, 10, 8, 4, 3, 2, 1};
	int i, j, swap, temp;
	printf("Data items in original order\n");
	for(i = 0; i < SIZE; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
	for(j = 0; j < SIZE - 1; j++) {
		swap = 0;
		for(i = 0; i < SIZE - j; i++) {
			if(a[i] > a[i + 1]) {
				swap = 1;
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
		printf("After pass %d:	", j);
		for(i = 0; i < SIZE - j; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		if(!swap) {
			break;
		}
	}
	printf("\nData items in accending order:\n");
	for(i = 0; i < SIZE; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}
