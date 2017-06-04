#include <stdio.h>
#include <string.h>
int main() {
	char a[100], b[100], c[100];
	char *p1, *p2, *p3;
	char *temp;
	gets(a);
	gets(b);
	gets(c);
	p1 = a;
	p2 = b;
	p3 = c;
	if(strcmp(p1, p2) > 0) {
		temp = p1;
		p1 = p2;
		p2 = temp;
	}
	if(strcmp(p1, p3) > 0) {
		temp = p1;
		p1 = p3;
		p3 = temp;
	}
	if(strcmp(p2, p3) > 0) {
		temp = p2;
		p2 = p3;
		p3 = temp;
	}
	printf("%s\n%s\n%s", p1, p2, p3);
	return 0;
}
