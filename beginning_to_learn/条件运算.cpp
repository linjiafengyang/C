#include <stdio.h>
int main() {
	int count = 0;
	while(++count <=100) {
		count % 10 == 0 ? printf("*\n") : printf("*");
	}
	return 0;
}

