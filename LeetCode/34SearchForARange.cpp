#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res;
		vector<int> res1;
		res1.push_back(-1);
		res1.push_back(-1);
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == target) {
				res.push_back(i);
				break;
			}
		}
		for (int i = nums.size() - 1; i >= 0; i--) {
			if (nums[i] == target) {
				res.push_back(i);
				break;
			}
		}
		if (res.size() == 0) {
			return res1;
		}
		return res;
	}
};
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res;
		vector<int> res1;
		res1.push_back(-1);
		res1.push_back(-1);
		if (nums.size() == 0) return res1;

		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = (left + right) / 2;
			if (nums[mid] < target) left = mid + 1;
			else right = mid;
		}
		if (nums[left] != target) return res1;
		else res.push_back(left);

		right = nums.size() - 1;
		while (left < right) {
			int mid = (left + right) / 2 + 1;
			if (nums[mid] > target) right = mid - 1;
			else left = mid;
		}
		res.push_back(right);
		return res;
	}
};
int main() {
	int n;
	vector<int> nums;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		nums.push_back(t);
	}
	int target;
	cin >> target;
	Solution s;
	vector<int> res = s.searchRange(nums, target);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}