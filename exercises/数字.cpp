#include <stdio.h>
int main() {
	int a, temp;
	int i;
	int count = 0;
	int b[5];
	scanf("%d", &a);
	temp = a;
	while(temp != 0) {
		b[count++] = temp % 10;
		temp /= 10;
	}
	printf("%d\n", count);
	for(i = count - 1; i >= 1; i--) {
		printf("%d ", b[i]);
	}
	printf("%d", b[0]);
	printf("\n");
	for(i = 0; i < count; i++) {
		printf("%d", b[i]);
	}
	printf("\n");
} 
