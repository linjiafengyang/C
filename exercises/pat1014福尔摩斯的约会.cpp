#include <stdio.h>
#include <string.h>
int main() {
	char str[4][61];
	memset(str, 0, sizeof(str));
	scanf("%s%s%s%s", str[0], str[1], str[2], str[3]);
	int len1 = strlen(str[0]);
	int len2 = strlen(str[1]);
	int len3 = strlen(str[2]);
	int len4 = strlen(str[3]);
	int i, j;
	for(i = 0, j = 0; i < len1 && j < len2; i++, j++) {
		if(str[0][i] == str[1][j] && str[0][i] >= 'A' && str[0][i] <= 'G') {
			switch(str[0][i]) {
				case 'A':printf("MON ");break;
				case 'B':printf("TUE ");break;
				case 'C':printf("WED ");break;
				case 'D':printf("THU ");break;
				case 'E':printf("FRI ");break;
				case 'F':printf("SAT ");break;
				case 'G':printf("SUN ");break;
			}
			break;
		}
	}
	for(i++, j++; i < len1 && j < len2; i++, j++) {
		if(str[0][i] == str[1][j] && (str[0][i] >= 'A' && str[0][i] <= 'N' || str[0][i] >= '0' && str[0][i] <= '9')) {
			int t = 0;
			if(str[0][i] >= 'A' && str[0][i] <= 'N') {
				t = str[0][i] - 'A' + 10;
			}
			else {
				t = str[0][i] - '0';
			}
			printf("%d%d:", t / 10, t % 10);
			break;
		}
	}
	for(i = 0, j = 0; i < len3 && j < len4; i++, j++) {
		if(str[2][i] == str[3][j] && (str[2][i] >= 'A' && str[2][i] <= 'Z' || str[2][i] >= 'a' && str[2][i] <= 'z')) {
			printf("%d%d\n", i / 10, i % 10);
			break;
		}
	}
}
