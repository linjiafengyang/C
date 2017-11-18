/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int size = nums.size();
		if (size == 0) return 0;
		int result = nums[0], maxValue = nums[0], minValue = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			int tempMax = max(nums[i], maxValue * nums[i]);// 最大值乘以一个数可能成为新的最大值
			int tempMin = min(nums[i], maxValue * nums[i]);// 最大值乘以一个负数可能成为最小值
			maxValue = max(tempMax, minValue * nums[i]);// 最小值乘以一个负数可能成为最大值
			minValue = min(tempMin, minValue * nums[i]);// 最小值乘以一个数可能成为新的最小值
			result = max(maxValue, result);
		}
		return result;
	}
};
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int size = nums.size();
		int frontProduct = 1, backProduct = 1;
		int result = INT_MIN;
		for (int i = 0; i < size; i++) {
			frontProduct *= nums[i];
			backProduct *= nums[size - i - 1];
			result = max(result, max(frontProduct, backProduct));
			frontProduct = frontProduct == 0 ? 1 : frontProduct;
			backProduct = backProduct == 0 ? 1 : backProduct;
		}
		return result;
	}
};
int main() {
	Solution s;
	int n;
	vector<int> nums(n);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << s.maxProduct(nums) << endl;
	return 0;
}