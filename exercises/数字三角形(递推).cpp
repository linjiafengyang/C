/*
动态规划：递推
 */
#include <iostream>
using namespace std;
int a[100][100];
int d[100][100];
int n;
int max(int a, int b) {
	return a > b ? a : b;
}
int maxsum() {
	for (int j = 1; j <= n; j++) d[n][j] = a[n][j];
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			d[i][j] = a[i][j] + max(d[i + 1][j], d[i + 1][j + 1]);
		}
	}
	return d[1][1];
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	cout << maxsum() << endl;
}