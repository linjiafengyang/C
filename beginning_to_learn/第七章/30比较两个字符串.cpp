#include <stdio.h>
int main() {
	char string1[80];
	char string2[80];
	printf("Enter two string2:");
	scanf("%s%s", string1, string2);
	printf("The result is %d\n", mystery3(string1, string2));
	return 0;
}
int mystery3(const char *s1, const char *s2) {
	for(; *s1 != '\0' && *s2 != '\0'; s1++, s2++) {
		if(*s1 != *s2) {
			return 0;
		}
	}
	return 1;
}
