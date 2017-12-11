#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int before, after;
		bool flag = false;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i += 2) {
			// 这里i += 2，说明这两个数相等，遍历直接跳过nums[i+1]
			// 不等时，记录下flag和当前遍历的位置
			if (nums[i] != nums[i + 1]) {
				flag = true;
				before = i;
				after = i + 1;
				break;
			}
		}
		// flag为真表示single number不是最大的一个数，
		// 该数处于已排序的数组中间，nums[after+1]是可以遍历到的
		if (flag) {
			if (nums[after] != nums[after + 1]) {
				return nums[after];
			}
			else {
				return nums[before];
			}
		}
		// 表示single number是最大的一个数，无法遍历到，返回该数即是结果
		else {
			return nums[nums.size() - 1];
		}

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
	cout << s.singleNumber(nums) << endl;
	return 0;
}