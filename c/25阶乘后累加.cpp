#include <stdio.h>
int main() {
	int sum, mix, i;
	sum = 0;
	mix = 1;
	for(i = 1; i <= 20; i++) {
		mix = mix * i;
		sum += mix;
	}
	printf("%d\n", sum);
	return 0;
}
