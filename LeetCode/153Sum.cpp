#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int> > threeSum(vector<int>& nums) {
		vector<vector<int> > result;
		int n = nums.size();
		if (n < 3) return result;
		sort(nums.begin(), nums.end());
		vector<int> temp(3);
		for (int i = 0; i < n; i++) {
			if (nums[i] > 0) break;
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int begin = i + 1, end = n - 1;
			while (begin < end) {
				int sum = nums[i] + nums[begin] + nums[end];
				if (sum == 0) {
					temp[0] = nums[i];
					temp[1] = nums[begin];
					temp[2] = nums[end];
					result.push_back(temp);
					begin++;
					end--;
					while (begin < end && nums[begin] == nums[begin - 1]) begin++;
					while (begin < end && nums[end] == nums[end + 1]) end--;
				}
				else if (sum > 0) {
					end--;
				}
				else {
					begin++;
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
	Solution s;
	vector<vector<int> > result = s.threeSum(nums);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}