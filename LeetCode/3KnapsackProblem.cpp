/*
可重复背包（多副本背包）：
有N种物品和一个容量为V的背包，每种物品都有无限件可用。
第i种物品的费用是c[i]，，价值是w[i]
求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大
 */
#include <iostream>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}
// （空间复杂度为O(V)
int KP(int N, int V, int c[], int w[]) {
	int f[V + 1];
	for (int v = 0; v <= V; v++) {
		f[v] = 0;
	}
	for (int v = 1; v <= V; v++) {
		for (int i = 1; i <= N; i++) {
			if (v >= c[i]) {
				f[v] = max(f[v], f[v - c[i]] + w[i]);
			}
		}
	}
	for (int v = 0; v <= V; v++) {
		cout << f[v] << " ";
	}
	cout << endl;
	return f[V];
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