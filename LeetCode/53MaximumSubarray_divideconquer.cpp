// 分治法O(nlogn)
// 根据算法导论
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
// 存储结果：最大子数组的下标以及和
struct PositionASum {
	int low;
	int high;
	int sum;
};
// 寻找包含中点位置的最大子数组函数
PositionASum MaxCrossingSubarray(int a[], int low, int mid, int high) {
	// 求中点左边的最大值和最大位置
	int maxLeft;// 记录左边的最大位置
	int maxSumLeft = -1000000;// 记录左边的最大和
	int sumLeft = 0;
	for (int i = mid; i >= low; i--) {
		sumLeft += a[i];
		if (sumLeft > maxSumLeft) {
			maxSumLeft = sumLeft;
			maxLeft = i;
		}
	}
	// 求中点右边的最大值和最大位置
	int maxRight = mid + 1;// 记录右边的最大位置
	int maxSumRight = -1000000;// 记录右边的最大和
	int sumRight = 0;
	for (int i = mid + 1; i <= high; i++) {
		sumRight += a[i];
		if (sumRight > maxSumRight) {
			maxSumRight = sumRight;
			maxRight = i;
		}
	}
	PositionASum p;
	p.low = maxLeft;
	p.high = maxRight;
	p.sum = maxSumLeft + maxSumRight;
	return p;
}
// 分治法左右
PositionASum FindMaxSubArray(int a[], int low, int high) {
	if (low == high) {
		PositionASum p;
		p.low = low;
		p.high = high;
		p.sum = a[low];
		return p;
	}
	else {
		int mid = (low + high) / 2;
		PositionASum left = FindMaxSubArray(a, low, mid);
		PositionASum right = FindMaxSubArray(a, mid + 1, high);
		PositionASum cross = MaxCrossingSubarray(a, low, mid, high);
		if (left.sum >= cross.sum && left.sum >= right.sum) {
			return left;
		}
		else if (right.sum >= left.sum && right.sum >= cross.sum) {
			return right;
		}
		else {
			return cross;
		}
	}
}
int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	PositionASum res = FindMaxSubArray(a, 0, n);
	cout << "low: " << res.low << endl << "right: " << res.high << endl << "MaximumSubarray: " << res.sum << endl;
	return 0;
}