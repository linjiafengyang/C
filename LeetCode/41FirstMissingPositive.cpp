#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			if (nums[i] != i + 1) {
				if (nums[i] > 0 && nums[i] <= len && nums[nums[i] - 1] != nums[i]) {
					swap(nums[i], nums[nums[i] - 1]);
					i--;
				}
			}
		}
		for (int i = 0; i < len; i++) {
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}
		return len + 1;
	}
};
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		for (int i = 0; i < len; i++) {
			while (nums[i] > 0 && nums[i] <= len && nums[nums[i] - 1] != nums[i]) {
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0; i < len; i++) {
			if (nums[i] != i + 1) {
				return i + 1;
			}
		}
		return len + 1;
	}
};
int main() {
	Solution s;
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		nums.push_back(t);
	}
	cout << s.firstMissingPositive(nums) << endl;
}