#include <stdio.h>
int main() {
	int a[100][100];
	int n, i, j;
	scanf("%d", &n);
	a[0][0] = 1;
	for(i = 0; i < n; i++) {
		a[i + 1][0] = a[i][0] + 1 + i;
	}
	for(j = 1; j < n; j++) {
		for(i = 0; i < n - j; i++) {
			a[i][j] = a[i + 1][j - 1] + 1;
		}
	}
	for(i = 0; i < n; i++) {
		for(j = 0; j < n - i; j++) {
			if(j < n - i - 1) {
				printf("%d ", a[i][j]);
			}
			else {
				printf("%d", a[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
//ÉßÐÎ¾ØÕó
/* 1 3 6 10 15
2 5 9 14
4 8 13
7 12
11*/ 
