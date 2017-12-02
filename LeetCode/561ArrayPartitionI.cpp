#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int sum = 0;
		for (int i = 0; i < n; i += 2) {
			cout << min(nums[i], nums[i + 1]) << endl;
			sum += min(nums[i], nums[i + 1]);
		}
		return sum;
	}
};
int main() {
	Solution s;
	int n;
	cin >> n;
	vector<int> nums(n * 2);
	for (int i = 0; i < n * 2; i++) {
		cin >> nums[i];
	}
	cout << s.arrayPairSum(nums) << endl;
	return 0;
}