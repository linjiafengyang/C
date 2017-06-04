#include <stdio.h>
int main() {
	char s[100];
	scanf("%s", s);
	int i, j;
	printf("%c", s[0]);
	for(i = 1; s[i] != '\0'; i++) {
		int temp = 1;
		for(j = i - 1; j >= 0; j--) {
			if(s[j] == s[i]) {
				temp = 0;
			}
		}
		if(temp) {
			printf("%c", s[i]);
		}
	}
}
//abacaeedabcdcd
//abced
