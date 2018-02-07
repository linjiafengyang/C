#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int k = -1;
		for (int i = nums.size() - 2; i >= 0; i--) {
			if (nums[i] < nums[i + 1]) {
				k = i;
				break;
			}
		}
		if (k == -1) {
			reverse(nums.begin(), nums.end());
			return;
		}
		int m = -1;
		for (int i = nums.size() - 1; i > k; i--) {
			if (nums[i] > nums[k]) {
				m = i;
				break;
			}
		}
		swap(nums[k], nums[m]);
		reverse(nums.begin() + k + 1, nums.end());
	}
};
// class Solution {
// public:
// 	void nextPermutation(vector<int>& nums) {
// 		next_permutation(nums.begin(), nums.end());
// 	}
// };
int main() {
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		nums.push_back(t);
	}
	Solution s;
	s.nextPermutation(nums);
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
	return 0;
}