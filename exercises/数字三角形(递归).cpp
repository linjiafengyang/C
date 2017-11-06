/*
动态规划：递归计算
 */
#include <iostream>
using namespace std;
int a[100][100];
int n;
int max(int a, int b) {
	return a > b ? a : b;
}
int maxsum(int i, int j) {
	return a[i][j] + (i == n ? 0 : max(maxsum(i + 1, j), maxsum(i + 1, j + 1)));
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	cout << maxsum(1, 1) << endl;
}