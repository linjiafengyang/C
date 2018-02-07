#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0, right = nums.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (nums[mid] == target) return mid;
			if (nums[left] <= nums[mid]) {
				if (target >= nums[left] && target < nums[mid]) 
					right = mid - 1;
				else left = mid + 1;
			}
			else {
				if (target > nums[mid] && target <= nums[right]) 
					left = mid + 1;
				else right = mid - 1;
			}
		}
		return -1;
	}
};
// another solution
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int n = nums.size();
		int left = 0, right = n - 1;
		while (left < right) {
			int mid = (left + right) / 2;
			if (nums[mid] > nums[right]) left = mid + 1;
			else right = mid;
		}
		int small = left;
		left = 0;
		right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			int realmid = (mid + small) % n;
			if (nums[realmid] == target) return realmid;
			if (nums[realmid] < target) left = mid + 1;
			else right = mid - 1;
		}
		return -1;
	}
};
int main() {
	int n;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		nums.push_back(t);
	}
	int target;
	cin >> target;
	Solution s;
	cout << s.search(nums, target) << endl;
	return 0;
}