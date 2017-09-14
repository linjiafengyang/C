/*
分数拆分：输入k，1/k=1/x+1/y，其中x>=y
分析：
x>=y可得1/x小于等于1/y，即1/k-1/y小于等于1/y，可得y小于等于2k
 */
#include <iostream>
using namespace std;
int main() {
	int x, y, k;
	while (scanf("%d", &k) == 1) {
		for (y = k + 1; y <= 2 * k; y++) {
			x = ((k * y) % (y - k)) ? 0 : ((k * y) / (y - k));
			if (x) {
				cout << "1/" << k << " = " << "1/" << x << " + 1/" << y << endl;
			}
		}
	}
	return 0;
}