/*
Given an unsorted array of integers, find the length of longest continuous increasing subsequence.
Input:
5
1 3 5 4 7
Output:
3
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int findLengthOfLCIS(vector<int>& nums) {
		vector<int> length(nums.size());
		for (int i = 0; i < nums.size(); i++) {
			length[i] = 1;
		}
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] > nums[i - 1]) {
				length[i] = length[i - 1] + 1;
			}
		}
		// 找出最大的length
		int max = 0;
		for (int i = 0; i < nums.size(); i++) {
			cout << length[i] << " ";
			if (length[i] > max) max = length[i];
		}
		cout << endl;
		return max;
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
	cout << s.findLengthOfLCIS(nums) << endl;
	return 0;
}