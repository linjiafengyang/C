#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != i) return i;
		}
		return nums.size();
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
	cout << s.missingNumber(nums) << endl;
	return 0;
}