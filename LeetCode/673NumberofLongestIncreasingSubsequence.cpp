/*
Given an unsorted array of integers, find the number of longest increasing subsequence.
Input:
5
1 3 5 4 7
Output:
2
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();
		vector<int> length(nums.size());// 最长递增子序列的长度
		vector<int> counts(nums.size());// 记录最长递增子序列的个数
		// 初始化置为1
		for (int i = 0; i < nums.size(); i++) {
			length[i] = 1;
			counts[i] = 1;
		}
		cout << counts[0] << endl;
		for (int i = 1; i < nums.size(); i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					if (length[i] < length[j] + 1) {
						length[i] = length[j] + 1;
						counts[i] = counts[j];
					}
					else if (length[i] == length[j] + 1) {
						counts[i] += counts[j];
					}
					cout << counts[i] << " ";
				}
			}
			cout << endl;
		}
		int max = 0, count = 0;
		for (int i = 0; i < nums.size(); i++) {
			// cout << counts[i] << " ";
			if (length[i] > max) {
				max = length[i];
			}
		}
		// cout << endl;
		for (int i = 0; i < nums.size(); i++) {
			if (length[i] == max) {
				count += counts[i];
			}
		}
		return count;
	}
};
int main() {
	Solution s;
	cout << "Input:" << endl;
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	cout << "Output:" << endl;
	cout << "Answer: " << s.findNumberOfLIS(nums) << endl;
	return 0;
}