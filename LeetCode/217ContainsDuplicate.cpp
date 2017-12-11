#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		if (nums.size() == 0) return false;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i++) {
			if (nums[i] == nums[i + 1]) return true;
		}
		return false;
	}
};
int main() {
	Solution s;
	vector<int> nums;
	int n;
	cin >> n;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		nums.push_back(t);
	}
	cout << s.containsDuplicate(nums) << endl;
	return 0;
}