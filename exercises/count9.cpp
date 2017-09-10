/*
计算两个数相加需要进位多少次
 */
#include <iostream>
using namespace std;
int main() {
	int a, b;
	while (scanf("%d%d", &a, &b) == 2) {
		if (!a && !b) return 0;
		int c = 0, ans = 0;
		for (int i = 9; i >= 0; i--) {
			c = (a % 10 + b % 10 + c) > 9 ? 1 : 0;
			ans += c;
			a /= 10;
			b /= 10;
		}
		cout << ans << endl;
	}
	return 0;
}