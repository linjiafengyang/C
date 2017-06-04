#include <stdio.h>
int multiple(int a, int b);
int even(int a); 
int main() {
	int x, y, i;
	for(i = 1; i <= 3; i++) {
		scanf("%d%d", &x, &y);
		if(multiple(x, y)) {
			printf("%d is a multiple of %d\n", y, x);
		}
		else {
			printf("%d is not a multiple of %d\n", y, x);
		}
		if(even(x)) {
			printf("%d is an even integer\n", x);
		}
		else {
			printf("%d is not an even integer\n", x);
		}
	}
	return 0;
}
int multiple(int a, int b) {
	return !(b % a);
}
int even(int a) {
	return !(a % 2);
}
