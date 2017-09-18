/*
图像过滤
 */
#include <iostream>
using namespace std;
int main() {
	int m, n;
	int a, b, c;
	cin >> m >> n >> a >> b >> c;
	int temp[m][n], ans[m][n];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp[i][j];
			if (temp[i][j] >= a && temp[i][j] <= b) {
				temp[i][j] = c;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (j == n - 1) printf("%03d", temp[i][j]);
			else printf("%03d ", temp[i][j]);
		}
		printf("\n");
	}
	return 0;
}