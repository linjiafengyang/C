#include <iostream>
using namespace std;
int maxsum(int* A, int x, int y) {
	int i, m, v, L, R, max;
	if (y - x == 1) return A[x];// 只有一个元素，直接返回
	m = x + (y - x) / 2;// 分治第一步：划分成[x, m]和[m, y]
	// 分治第二步：递归求解
	if (maxsum(A, x, m) > maxsum(A, m, y)) max = maxsum(A, x, m);
	else max = maxsum(A, m, y);
	v = 0;
	L = A[m - 1];// 分治第三步：合并——从分界点开始往左的最大连续和L
	for (i = m - 1; i >= x; i--) {
		v += A[i];
		if (L < v) L = v;
	}
	v = 0;
	R = A[m];// 分治第三步：合并——从分界点开始往右的最大连续和L
	for (i = m; i < y; i++) {
		v += A[i];
		if (R < v) R = v;
	}
	// 把子问题的解与L和R比较
	if (max > L + R) return max;
	else return L + R;
}
int main() {
	int A[6];
	for (int i = 0; i < 6; i++) {
		cin >> A[i];
	}
	cout << maxsum(A, 0, 6) << endl;
	return 0;
}