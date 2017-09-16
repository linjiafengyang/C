/*
算法导论书本上面提出这样的一种方法：从数组的左边界开始，
从左到右处理，记录到目前为止已经处理过的最大子数组。
若已知A[1,2,....,j]的最大子数组，则A[1,2,.....,j,j+1]的最大子数组
要么是A[1,2,....,j]的最大子数组，
要么是某个子数组A[i,....,j+1](1<=i<=j+1)。基于这一思路我的实现过程如下：
O(n^2)
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
	int low = 0;// 记录子数组的底
	int high = 0;// 记录子数组的高
	int max_sum = a[0];// 记录最大子数组的和
	for (int i = 0; i < n - 1; i++) {
		int sum = 0;
		// 寻找以A[i+1]为终点的最大子数组
		for (int j = i + 1; j >= 0; j--) {
			sum += a[j];
			if (sum > max_sum) {
				max_sum = sum;
				low = j;
				high = i + 1;
			}
		}
	}
	cout << "low: " << low << endl << "right: " << high << endl << "MaximumSubarray: " << max_sum << endl;
	return 0;
}