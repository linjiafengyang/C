#include <stdio.h>
void mystery1(char *s1, const char *s2);
int main() {
	char string1[80];
	char string2[80];
	printf("Enter two string:");
	scanf("%s%s", string1, string2);
	mystery1(string1, string2);
	printf("%s", string1);
	return 0;
}
void mystery1(char *s1, const char *s2) {
	while(*s1 != '\0') {
		s1++;
	}
	for(; *s1 = *s2; s1++, s2++) {
		;
	}
}
