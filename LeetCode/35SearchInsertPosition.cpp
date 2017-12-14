#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); i++) {
			if (target == nums[i]) {
				return i;
			}
			else if (target < nums[i]) {
				return i;
			}
		}
		return nums.size() + 1;
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
	int target;
	cin >> target;
	cout << s.searchInsert(nums, target);
	return 0;
}