#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int jump(vector<int>& nums) {
		int size = nums.size();
		int step = 0, start = 0, end = 0;
		while (end < size - 1) {
			step++;
			int maxend = end + 1;
			for (int i = start; i <= end; i++) {
				if (i + nums[i] >= size - 1) return step;
				maxend = max(maxend, i + nums[i]);
			}
			start = end + 1;
			end = maxend;
		}
		return step;
	}
};
int main() {
	vector<int> nums;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		nums.push_back(t);
	}
	Solution s;
	cout << s.jump(nums) << endl;
	return 0;
}