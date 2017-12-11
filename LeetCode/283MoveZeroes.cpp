#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int cnt = 0;
		for (vector<int>::iterator iter = nums.begin(); cnt != nums.size() && iter != nums.end();) {
			if (*iter == 0) {
				iter = nums.erase(iter);
				nums.push_back(0);
			}
			else {
				iter++;
			}
			cnt++;
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
	s.moveZeroes(nums);
	for (int i = 0; i < n; i++) {
		cout << nums[i] << " ";
	}
	return 0;
}