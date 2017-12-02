#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> res;
		vector<bool> hash(nums.size() + 1, false);
		for (int i = 0; i < nums.size(); i++) {
			if (hash[nums[i]] == true) {
				res.push_back(nums[i]);
			}
			else {
				hash[nums[i]] = true;
			}
		}
		return res;
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
	vector<int> temp = s.findDuplicates(nums);
	for (int i = 0; i < temp.size(); i++) {
		cout << temp[i] << " ";
	}
	return 0;
}