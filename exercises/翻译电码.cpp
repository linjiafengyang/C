#include <stdio.h>
#define MAX 80
#define CHANGE 1
int main() {
	char s[MAX];
	int i = 0;
	gets(s);
	while(s[i] != '\0') {
		if(CHANGE) {
			if(s[i] >= 97 && s[i] <= 121 || s[i] >= 65 && s[i] <= 89) {
				s[i] = s[i] + 1;
			}
			else if(s[i] == 90 || s[i] == 122) {
				s[i] = s[i] - 25;
			}
		}
		i++;
	}
	puts(s);
}
