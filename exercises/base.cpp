/*
进制转换:十进制转n进制
 */
#include <iostream>
using namespace std;
int main() {
	int b, n;
	cin >> b >> n;
	int a[100000];
	int k;
	while (n > 0) {
		a[k] = n % b;
		n /= b;
		k++;
	}
	for (int i = k - 1; i >= 0; i--) {
		cout << a[i];
	}
	return 0;
}