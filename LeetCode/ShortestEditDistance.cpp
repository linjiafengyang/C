/*
最小编辑距离：
input:
EXPONENTIAL
POLYNOMIAL
output：
6

input：
SNOWY
SUNNY
output：
3
 */
#include <iostream>
#include <cstring>
using namespace std;

int min(int a, int b, int c) {
	int temp = a < b ? a : b;
	return temp < c ? temp : c;
}
int SED(string a, string b) {
	int E[a.length() + 1][b.length() + 1];
	// 初始化
	for (int i = 0; i <= a.length(); i++) {
		E[i][0] = i;
	}
	for (int i = 0; i <= b.length(); i++) {
		E[0][i] = i;
	}
	// 算法关键实现
	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			int cost = (a[i - 1] == b[j - 1] ? 0 : 1);
			E[i][j] = min(E[i - 1][j] + 1, E[i][j - 1] + 1, E[i - 1][j - 1] + cost);
		}
	}
	// 输出二维矩阵E
	for (int i = 0; i <= a.length(); i++) {
		for (int j = 0; j <= b.length(); j++) {
			cout << E[i][j] << " ";
		}
		cout << endl;
	}
	// 返回结果
	return E[a.length()][b.length()];
}
int main() {
	string a, b;
	cin >> a >> b;
	cout << SED(a, b) << endl;
	return 0;
}
