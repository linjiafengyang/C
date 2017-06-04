#include <stdio.h>
#define L 50 
int main() {
	int i, j, k, n;
	int mat[L][L];
	int value = 1;
	scanf("%d", &n);
	for(k = 0; k < (n + 1) / 2; k++) {
		for(i = k; i < n - k; i++) {
			mat[k][i] = value++;
		}
		for(i = k + 1; i < n - k; i++) {
			mat[i][n - k - 1] = value++;
		}
		for(i = n - k - 2; i >= k; i--) {
			mat[n - k - 1][i] = value++;
		}
		for(i = n - k - 2; i > k; i--) {
			mat[i][k] = value++;
		}
	}

	for(i = 0; i < n; i++) {
		for(j = 0; j < n - 1; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("%d", mat[i][j]);//只是为了符合sicily输出每一行最后一个数不留空格，所以n-1，把n独立出来 
		printf("\n");
	}
} 
/*4
1 2 3 4
12 13 14 5
11 16 15 6
10 9 8 7 */
