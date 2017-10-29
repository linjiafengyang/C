/*
二维背包：
对于每件物品，具有两种不同的费用；选择这件物品必须同时付出这两种代价；
对于每种代价都有一个可付出的最大值（背包容量）。
设第i件物品所需的两种代价分别为a[i]和b[i].
两种代价可付出的最大值（两种背包容量）分别为V和U
物品的价值为w[i]
问：怎样选择物品可以得到最大的价值？
 */
#include <iostream>
using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int KP(int N, int V, int U, int a[], int b[], int w[]) {
	int f[V + 1][U + 1];
	for (int v = 0; v <= V; v++) {
		for (int u = 0; u <= U; u++) {
			f[v][u] = 0;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int v = V; v >= a[i]; v--) {
			for (int u = U; u >= b[i]; u--) {
				f[v][u] = max(f[v][u], f[v - a[i]][u - b[i]] + w[i]);
			}
		}
	}
	for (int v = 0; v <= V; v++) {
		for (int u = 0; u <= U; u++) {
			cout << f[v][u] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return f[V][U];
}
int main() {
	int N, V, U;
	cin >> N >> V >> U;
	int a[N + 1], b[N + 1], w[N + 1];
	for (int i = 1; i <= N; i++) {
		cin >> a[i] >> b[i] >> w[i];
	}
	cout << KP(N, V, U, a, b, w) << endl;
	return 0;
}
