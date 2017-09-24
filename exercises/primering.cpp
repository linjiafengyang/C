/*
素数环
 */
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int A[10000];
int isp[10000];
int is_prime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return 0;
	}
	return 1;
}
int main() {
	cin >> n;
	for (int i = 2; i < n * 2; i++) {// 生成素数表，加快后续判断
		isp[i] = is_prime(i);
	}
	for (int i = 0; i < n; i++) A[i] = i + 1;// 第一个排列
	do {
		int ok = 1;
		for (int i = 0; i < n; i++) {
			if (!isp[A[i] + A[(i + 1) % n]]) {// 判断合法性
				ok = 0;
				break;
			}
		}
		if (ok) {
			for (int i = 0; i < n; i++) cout << A[i] << " ";// 输出合法序列
			cout << endl;
		}
	} while (next_permutation(A + 1, A + n));
	return 0;
}