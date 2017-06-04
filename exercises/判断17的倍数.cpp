#include <stdio.h>
int main() {
	int d[110];
	int i, j;
	int c, a;
	int m = 0;
	char n[110];
	scanf("%s", n);
	for(i = 0; n[i] != '\0'; i++) {
		m++;
		d[i] = n[i] - 48;
	}
	c = d[0];
	while(c != 0) {
		for(i = 1; i < m; i++) {
			a = c * 10 + d[i];
			c = a % 17;
		}
		if(c == 0) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
		scanf("%s", n);
		m = 0;
		for(i = 0; n[i] != '\0'; i++) {
			m++;
			d[i] = n[i] - 48;
		}
		c = d[0];
	}
}
