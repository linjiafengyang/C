/*
时间复杂度为O(nlogn)
 */
#include <iostream>
using namespace std;

// 二分查找，返回数组元素需要插入的位置
int BiSearch(int b[], int len, int value) {
	int left = 0, right = len - 1;
	int mid;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (b[mid] > value) {
			right = mid - 1;
		}
		else if (b[mid] < value) {
			left = mid + 1;
		}
		else {
			return mid;
		}
	}
	return left;
}

int LIS(int arr[], int len) {
	int resLen = 1;// 用于记录B数组中的元素个数，最终结果即为最长长度
	int B[len];// 在动态规划中使用的数组，用于记录中间结果
	B[0] = arr[0];

	for (int i = 1; i < len; i++) {
		if (arr[i] > B[resLen - 1]) {// 如果大于B中最大的元素，则直接插入到B数组末尾
			B[resLen] = arr[i];
			++resLen;
		}
		else {
			int pos = BiSearch(B, resLen, arr[i]);// 二分查找需要插入的位置
			B[pos] = arr[i];
		}
	}
	// 输出B数组的结果
	for (int i = 0; i < resLen; i++) {
		cout << "B[" << i << "]=" << B[i] << endl;
	}
	return resLen;
}

int main() {
	int array[] = {5, 2, 8, 6, 3, 6, 9, 7};// 测试数组
	cout << "LIS: " << LIS(array, sizeof(array) / sizeof(array[0]));
	return 0;
}
