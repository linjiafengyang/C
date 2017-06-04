#include <stdio.h>
#include <string.h>
int main() {
	char s1[1000], s2[1000];
	char a, b;
	int c = 0, d = 0;
	scanf("%s %c %s %c", s1, &a, s2, &b);
	for(int i = strlen(s1) - 1; i >= 0; i--) {
		if(s1[i] == a) {
			c = c * 10 + a - '0';
		}
	}
	for(int i = strlen(s2) - 1; i >= 0; i--) {
		if(s2[i] == b) {
			d = d * 10 + b - '0';
		}
	}
	printf("%d\n", c + d);
}
