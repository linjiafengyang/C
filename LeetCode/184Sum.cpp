#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > fourSum(vector<int>& nums, int target) {
		vector<vector<int> > result;
		int n = nums.size();
		if (n < 4) return result;
		sort(nums.begin(), nums.end());
		vector<int> temp(4);
		for (int i = 0; i < n - 3; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (int j = i + 1; j < n - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				int begin = j + 1, end = n - 1;
				while (begin < end) {
					int sum = nums[i] + nums[j] + nums[begin] + nums[end];
					if (sum == target) {
						temp[0] = nums[i];
						temp[1] = nums[j];
						temp[2] = nums[begin];
						temp[3] = nums[end];
						result.push_back(temp);
						begin++;
						end--;
						while (begin < end && nums[begin] == nums[begin - 1]) begin++;
						while (begin < end && nums[end] == nums[end + 1]) end--;
					}
					else if (sum > target) {
						end--;
					}
					else {
						begin++;
					}
				}
			}
		}
		return result;
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
	vector<vector<int> > result = s.fourSum(nums, target);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}