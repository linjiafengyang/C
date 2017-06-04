#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int hashtable[100] = {};
	int i, j, len1, len2;
	char s1[100], s2[100];
	gets(s1);
	gets(s2);
	len1 = strlen(s1);
	len2 = strlen(s2);
	for (i = 0; i < len1; i++) {
		char c1 = s1[i];
		for (j = 0; j < len2; j++) {
			char c2 = s2[j];
			if (c1 >= 'a' && c1 <= 'z') {
				c1 = c1 - 32;
			}
			if (c2 >= 'a' && c2 <= 'z') {
				c2 = c2 - 32;
			}
			if (c1 == c2) break;
		}
		if (j == len2 && hashtable[c1] == 0) {
			printf("%c", c1);
			hashtable[c1] = 1;
		}
	}
	return 0;
}
