#include <stdio.h>
int main() {
	int i, largest, j;
	int a[8];
	for(i = 0; i < 8; i++) {
		scanf("%d", &a[i]);
	}
	largest = a[0];
	for(i = 0; i < 8; i++) {
		if(a[i] > largest) {
			largest = a[i];
			j = i;
		}
	}
	for(i = 0; i < 8; i++) {
		if(i == 0) {
			printf("%d\n", largest);
		}
		else if(i == j) {
			printf("%d\n", a[0]);
		}
		else {
			printf("%d\n", a[i]);
		}
	}
	return 0;
}
// ÊäÈë 1 2 3 4 5 6 7 8 Êä³ö 8 2 3 4 5 6 7 1 
