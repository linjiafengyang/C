/*
孪生素数n和n+2都为素数，找出最大的孪生素数
 */
#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;
bool is_prime(int x) {
	int m;
	assert(x >= 0);
	if (x == 1) return false;
	m = floor(sqrt(x) + 0.5);
	for (int i = 2; i <= m; i++) {
		if (x % i == 0) return false;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	for (int i = n - 2; i >= 3; i--) {
		if (is_prime(i) && is_prime(i + 2)) {
			cout << i << " " << i + 2;
			break;
		}
	}
	return 0;
}