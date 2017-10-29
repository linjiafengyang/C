/*
单副本背包问题：
有N件物品和一个容量为V的背包。第i件物品的体积是c[i]，价值为w[i]
求解将哪些物品装入背包可使价值总和最大。
 */
#include <iostream>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}
// （空间复杂度为O(NV)
int KP(int N, int V, int c[], int w[]) {
	int f[N + 1][V + 1];
	for (int v = 0; v <= V; v++) {
		f[0][v] = 0;
	}
	for (int i = 1; i <= N; i++) {
		for (int v = 0; v <= V; v++) {
			if (v < c[i]) f[i][v] = f[i - 1][v];
			else f[i][v] = max(f[i - 1][v], f[i - 1][v - c[i]] + w[i]);
		}
	}
	for (int i = 0; i <= N; i++) {
		for (int v = 0; v <= V; v++) {
			cout << f[i][v] << " ";
		}
		cout << endl;
	}
	return f[N][V];
}
int main() {
	int N, V;
	cin >> N >> V;
	int c[N + 1], w[N + 1];
	for (int i = 1; i <= N; i++) {
		cin >> c[i] >> w[i];
	}
	cout << KP(N, V, c, w) << endl;
	return 0;
}