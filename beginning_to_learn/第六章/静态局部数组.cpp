#include <stdio.h>
void staticArrayInit(void);
void automaticArrayInit(void);
int main() {
	printf("First call to each function:\n");
	staticArrayInit();
	automaticArrayInit();
	printf("\n\nSecond call to each function:\n");
	staticArrayInit();
	automaticArrayInit();
	return 0;
}
void staticArrayInit(void) {
	static int array1[3];
	int i;
	for(i = 0; i < 3; i++) {
		printf("array1[%d] = %d ", i, array1[i]);
	}
	printf("\n");
	for(i = 0; i < 3; i++) {
		printf("array1[%d] = %d ", i, array1[i] += 5);
	}
	printf("\n");
}
void automaticArrayInit(void) {
	int array2[3] = {1, 2, 3};
	int i;
	for(i = 0; i < 3; i++) {
		printf("array2[%d] = %d ", i, array2[i]);
	}
	printf("\n");
	for(i = 0; i < 3; i++) {
		printf("array2[%d] = %d ", i, array2[i] += 5);
	}
	printf("\n");
}
