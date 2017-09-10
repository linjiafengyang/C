/*
组合数n!/(m!*(n-m)!)
 */
#include <iostream>
using namespace std;
int f(int a) {
	int res = 1;
	for (int i = 1; i <= a; i++) {
		res *= i;
	}
	return res;
}
int main() {
	int m, n;
	cin >> m >> n;
	cout << f(n) / (f(m) * f(n - m)) << endl;
	return 0;
}