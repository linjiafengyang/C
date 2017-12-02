#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> res;
		vector<bool> hash(nums.size() + 1, false);
		for (int i = 0; i < nums.size(); i++) {
			hash[nums[i]] = true;
		}
		for (int i = 1; i < hash.size(); i++) {
			if (hash[i] == false) {
				res.push_back(i);
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
	vector<int> temp = s.findDisappearedNumbers(nums);
	for (int i = 0; i < temp.size(); i++) {
		cout << temp[i] << " ";
	}
	return 0;
}