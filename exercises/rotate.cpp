/*
左旋n*n矩阵90°，输出
 */
#include <iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int b[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = a[j][n - 1 - i];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == n - 1) cout << b[i][j];
			else cout << b[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}