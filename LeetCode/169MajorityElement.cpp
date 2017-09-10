/*
Easy
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		// 22ms
		int cnt = 0;
		int vote;
		for (auto num : nums) {
			if (!cnt) vote = num;
			if (vote == num) cnt++;
			else cnt--;
		}
		return vote;
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
	cout << s.majorityElement(nums) << endl;
	return 0;
}
/*23ms
		sort(nums.begin(), nums.end());
		int res = nums[0];
		int cnt = 0, max = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[i - 1]) {
				cnt++;
				if (cnt >= (nums.size() - 1) / 2) {
					res = nums[i];
				}
			}
			else {
				cnt = 0;
			}
		}
		return res;
 */
/*26ms
		sort(nums.begin(), nums.end());
		int res = nums[0];
		int cnt = 0, max = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[i - 1]) {
				cnt++;
				if (cnt > max) {
					max = cnt;
					res = nums[i];
				}
			}
			else {
				cnt = 0;
			}
		}
		return res;
*/