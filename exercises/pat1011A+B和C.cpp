#include <stdio.h>
int main() {
	int T, i;
	long long a[11] = {0}, b[11] = {0}, c[11] = {0};
	scanf("%d", &T);
	for(i = 1; i <= T; i++) {
		scanf("%ld%ld%ld", &a[i], &b[i], &c[i]);
	}
	for(i = 1; i <= T; i++) {
		if(a[i] + b[i] > c[i]) {
			printf("Case #%d: true\n", i);
		}
		else {
			printf("Case #%d: false\n", i);
		}
	}
}
