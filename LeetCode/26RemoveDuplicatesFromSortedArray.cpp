#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int temp = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[temp] != nums[i]) {
				temp++;
				nums[temp] = nums[i];
			}
		}
		return temp + 1;
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
	cout << s.removeDuplicates(nums) << endl;
	return 0;
}