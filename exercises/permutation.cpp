#include <stdio.h>  
int main() {  
	int a, b, c, i, j, s[9];  
	for (a = 100; a < 333; a++) {
		b = 2 * a;
		c = 3 * a;  
		s[0] = a % 10;
		s[1] = a % 100 / 10;
		s[2] = a / 100;  
		s[3] = b % 10;
		s[4] = b % 100 / 10;
		s[5] = b / 100;  
		s[6] = c % 10;
		s[7] = c % 100 / 10;
		s[8] = c / 100;  
		for (i = 0; i < 8; i++) {
			for (j = i + 1; j < 9; j++)  
				if (s[i] == s[j]) break;  
				if (j < 9) break;  
		}
		if (i == 8 && j == 9) 
			printf("%d %d %d\n", a, b, c);
	}
	return 0;
}