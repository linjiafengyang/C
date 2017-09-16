#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
// 暴力求解法O(n^3)
int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	//int array_length = sizeof(A) / sizeof(A[0]);//数组大小
	int max_sum = -10000000;// 记录子数组的和，但是超过int的表示范围时有问题
	int low;// 记录子数组的底
	int height;// 记录子数组的高
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int array_sum = 0;// 记录所遍历的子数组的和
			// 计算遍历的子数组的和
			for (int k = i; k <= j; k++) {
				array_sum += a[k];
			}
			// 找出最大子数组
			if (array_sum > max_sum) {
				max_sum = array_sum;
				low = i;
				height = j;
			}
		}
	}
	cout << "low: " << low << endl << "right: " << height << endl << "MaximumSubarray: " << max_sum << endl;
}