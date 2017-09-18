/*

 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		/*超时
		vector<int> ans(2);
		for (int i = 0; i < nums.size(); i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (nums[i] + nums[j] == target) {
					ans[0] = i + 1;
					ans[1] = j + 1;
					return ans;
				}
			}
		}*/
		int low = 0, high = nums.size() - 1;
		while (nums[low] + nums[high] != target) {
			if (nums[low] + nums[high] < target) low++;
			else high--;
		}
		return vector<int>({low + 1, high + 1});// c++11
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
	cout << "[" << s.twoSum(nums, target)[0] << ", " << s.twoSum(nums, target)[1] << "]" << endl;
	return 0;
}