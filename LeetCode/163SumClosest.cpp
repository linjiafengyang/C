#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		long result = INT_MAX;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < n; i++) {
			int begin = i + 1, end = n - 1;
			while (begin < end) {
				int sum = nums[i] + nums[begin] + nums[end];
				if (sum == target) {
					begin++;
					end--;
				}
				else if (sum > target) {
					end--;
				}
				else {
					begin++;
				}
				if (abs(sum - target) < abs(result - target)) {
					result = sum;
				}
			}
		}
		return (int)result;
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
	cout << s.threeSumClosest(nums, target) << endl;
	return 0;
}