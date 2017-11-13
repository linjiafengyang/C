/*
Given an array consisting of n integers, find the contiguous subarray of given length k 
that has the maximum average value. And you need to output the maximum average value.
Input:
6
1 12 -8 -6 -5 50
5
Output:
1 13 5 -1 -6 44
8.6

Input:
5
4 0 4 3 3
5
Output:
2.8
 */
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Solution {
public:
	double findMaxAverage(vector<int>& nums, int k) {
		int len = nums.size();
		vector<int> sum(len);
		sum[0] = nums[0];
		//int max_sum = sum[0];
		for (int i = 1; i < len; i++) {
			sum[i] = nums[i] + sum[i - 1];
			//sum[i] = nums[i] + (sum[i - 1] > 0 ? sum[i - 1] : 0);
			//max_sum = max(max_sum, sum[i]);
		}
		//for (int i = 0; i < len; i++) {
			//cout << sum[i] << " ";
		//}
		//cout << endl;
		int max_sum = sum[k - 1];// 这里是因为当k与数组长度相等时，要初始化为sum数组最后一个数
		for (int i = 0; i < len - k; i++) {
			int temp = sum[i + k] - sum[i];
			max_sum = max(max_sum, temp);
		}
		return (double)max_sum / k;
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
	int k;
	cin >> k;
	cout << s.findMaxAverage(nums, k) << endl;
	return 0;
}