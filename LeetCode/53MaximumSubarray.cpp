/*
Easy
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */
// 在线法O(n)
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int len = nums.size();
		vector<int> sum(len);
		sum[0] = nums[0];
		int max_sum = sum[0];
		for (int i = 1; i < len; i++) {
			sum[i] = nums[i] + (sum[i - 1] > 0 ? sum[i - 1] : 0);
			max_sum = max(max_sum, sum[i]);
		}
		return max_sum;
	}
};

int main() {
	Solution s;
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << s.maxSubArray(nums) << endl;
	return 0;
}