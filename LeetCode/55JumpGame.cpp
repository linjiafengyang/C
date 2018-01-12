#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		int distance = 0;
		for (int i = 0; i < nums.size() - 1 && i <= distance; i++) {
			distance = max(distance, i + nums[i]);
		}
		return distance >= nums.size() - 1;
	}
};
int main() {
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	Solution s;
	cout << s.canJump(nums) << endl;
	return 0;
}