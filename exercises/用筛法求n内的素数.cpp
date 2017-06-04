#include <stdio.h>
#include <math.h>
int main() {
	int n;
	int i, j, temp;
	scanf("%d", &n);
	for(i = 2; i <= n; i++) {
		temp = 1;
		for(j = 2; j < i; j++) {
			if(i % j == 0) {
				temp = 0;
			}
		}
		if(temp != 0) {
			printf("%d\n", i);
		}
	} 
	return 0;
}
