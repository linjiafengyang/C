/*
Medium
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
 */
#include <iostream>
#include <vector>
using namespace std;
vector<int> majorityElement(vector<int>& nums) {
	// 12ms
	int cnt1 = 0, cnt2 = 0;
	int vote1 = 0, vote2 = 0;
	for (auto num : nums) {
		if (num == vote1) cnt1++;
		else if (num == vote2) cnt2++;
		else if (!cnt1) cnt1 = 1, vote1 = num;
		else if (!cnt2) cnt2 = 1, vote2 = num;
		else cnt1--, cnt2--;
	}
	cnt1 = cnt2 = 0;
	for (auto num : nums) {
		if (num == vote1) cnt1++;
		else if (num == vote2) cnt2++;
	}
	vector<int> ans;
	if (cnt1 > nums.size() / 3) ans.push_back(vote1);
	if (cnt2 > nums.size() / 3) ans.push_back(vote2);
	return ans;
}
int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	vector<int> re = majorityElement(nums);
	for (int i = 0; i < re.size(); i++) {
		cout << re[i] << endl;
	}
	return 0;
}