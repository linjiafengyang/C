/*
相比于暴力解法每一次都从i到j地重新计算一次，
这种算法每一次只需要在原来计算的基础上面加上一个数，
所以这种算法少了一层循环,时间复杂度为O(n^2)是一种比暴力解法要高效的解法
 */
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int sum = 0;// 最大子数列之和
	// 寻找最大子数列
	for (int i = 0; i < n; i++) {
		int curSum = 0;// 当前数列之和
		for (int j = i; j < n; j++) {
			curSum += a[j];
			if (curSum > sum) {
				sum = curSum;
			}
		}
	}
	if (sum < 0) {
		cout << '0' << endl;
	}
	else {
		cout << sum << endl;
	}
	return 0;
}