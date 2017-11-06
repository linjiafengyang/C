/*
动态规划：记忆化搜索
 */
#include <iostream>
#include <cstring>
using namespace std;
int a[100][100];
int d[100][100];
int n;
int max(int a, int b) {
	return a > b ? a : b;
}
int maxsum(int i, int j) {
	if (d[i][j] >= 0) return d[i][j];
	d[i][j] = a[i][j] + (i == n ? 0 : max(maxsum(i + 1, j), maxsum(i + 1, j + 1)));
	return d[i][j];
}
int main() {
	memset(d, -1, sizeof(d));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	cout << maxsum(1, 1) << endl;
}